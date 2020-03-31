#include "../include/cgate-yard.hpp"

CGateStream::CGateStream(CGateConnection &conn, std::string name, std::string regime)
{
    conn_ = &conn;
    name_ = name;
    regime_ = regime;

    if (name_ == "FORTS_FUTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_FUTCOMMON_REPL;scheme=|FILE|../ini/fut_common.ini|FORTS_FUTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn,
                                 "p2repl://FORTS_OPTCOMMON_REPL;scheme=|FILE|../ini/opt_common.ini|FORTS_OPTCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTINFO_REPL;scheme=|FILE|../ini/fut_info.ini|FORTS_FUTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTINFO_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTINFO_REPL;scheme=|FILE|../ini/opt_info.ini|FORTS_OPTINFO_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_PART_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_PART_REPL;scheme=|FILE|../ini/part.ini|FORTS_PART_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_POS_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_POS_REPL;scheme=|FILE|../ini/pos.ini|FORTS_POS_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MOEX_RATES_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MOEX_RATES_REPL;scheme=|FILE|../ini/rates.ini|MOEX_RATES_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_FUTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTTRADE_REPL;scheme=|FILE|../ini/fut_trades.ini|FORTS_FUTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "FORTS_OPTTRADE_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTTRADE_REPL;scheme=|FILE|../ini/opt_trades.ini|FORTS_OPTTRADE_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MCXCC_MDCOMMON_REPL")
    {
        lsn_ = new CGateListener(conn, "p2repl://MCXCC_MDCOMMON_REPL;scheme=|FILE|../ini/mcxcc_mdcommon.ini|MCXCC_MDCOMMON_REPL",
                                 CgateCallback, this, [this]() { return GetConfig(); });
    }
    else if (name_ == "MESSAGE_PUB")
    {
        //lsn_ = new CGateListener(conn, "p2mqreply://;ref=servlink",
        //                         "", CgateCallback, this);
    }
    else
    {
        throw "unknown stream";
    }
}

int32_t CGateStream::GetLifenum()
{

    if (lifeNumGetter)
    {
        return lifeNumGetter(name_);
    }
    return 0;
}
void CGateStream::SetLifenum(int32_t lifenum)
{
    if (lifeNumSetter)
    {
        lifeNumSetter(name_, lifenum);
    }
}

uint32_t CGateStream::CheckStateIfNeededOpen()
{

    return lsn_->CheckStateIfNeededOpen();
}

std::string CGateStream::GetConfig()
{

    std::stringstream ss;
    ss << "mode=" << regime_ << ";";
    ss << "lifenum=" << GetLifenum() << ";";
    for (auto &kvp : revisions)
    {
        //get table_id
        auto table_revision = kvp.second();
        std::string table_name = name_ + "/tables/" + kvp.first + "/index";
        std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register(table_name);
        std::cout << "table_idx " << idx << std::endl;
        if (table_revision > 0)
        {
            ss << "rev." << kvp.first << "=" << table_revision + 1 << ";";
            revisionsFilter.insert({idx, table_revision});
        }
        else
        {
            revisionsFilter.insert({idx, -1});
            ss << "rev." << kvp.first << "="
               << "0"
               << ";";
        }
    }
    return ss.str();
}

void CGateStream::Insert(struct cg_msg_streamdata_t &replmsg)
{
    auto msg_index = replmsg.msg_index;

    if (inserts.count(msg_index))
    {
        //std::cout << "Insert revision:" << replmsg.rev << std::endl;
        if (revisionsFilter[msg_index] < replmsg.rev)
        {
            revisionsFilter[msg_index] = replmsg.rev;
            inserts[msg_index]((void *)replmsg.data);
        }
        else
        {
            std::cout << "discard message with revision " << replmsg.rev << std::endl;
        }
    }
}

void CGateStream::InsertData(void *msg)
{
    struct cg_msg_data_t *replmsg = (struct cg_msg_data_t *)msg;
    auto msg_index = replmsg->msg_index;
    std::cout << "Insert Data index = " << msg_index << std::endl;
    if (inserts.count(msg_index))
    {
        std::cout << "exist for inserts , sould be updated" << std::endl;
        inserts[msg_index](msg);
    }
}

void CGateStream::SetOnline()
{
    online_ = true;
}

bool CGateStream::IsOnline()
{
    return online_;
}

void CGateStream::Commit()
{
    int i = 0;
    for (auto commit : commits)
    {
        commit(NULL);
    }
}

/*
struct Stream
{
    std::string name_;
    std::string regime_{"snapshot+online"};
    CGateListener *lsn_{0};
    CGateConnection *conn_{0};
    std::function<void(std::string, int32_t lifenum)> lifenum_setter_;
    std::function<int32_t(std::string)> lifenum_getter_;
    std::map<int32_t, int64_t> revisions_filter_;

    __inserts inserts;
    __loaders loaders;
    __commits commits;
    __revisions revisions;
    bool online_{false};

    Stream(std::string name)
    {
        name_ = name;
    }

    Stream(std::string name, std::string regime)
    {
        name_ = name;
        regime_ = regime;
    }

    std::string GetName()
    {
        return name_;
    }

    template <typename T>
    void AddTableAndHandler(std::string name, T &t)
    {
        std::string table_name = name_ + "/tables/" + name + "/index";
        std::cout << "table_name = " << table_name << std::endl;

        int idx = Registrator::Register<Stream>(table_name);

        if (t.events.count("insert"))
        {
            auto insert = [&t](void *data) {
                t.Insert(data);
            };
            inserts.insert({idx, insert});
        }

        if (t.events.count("load"))
        {
            auto loader = [&t](void *data, int size) {
                t.Load(data, size);
            };
            loaders.insert({name, loader});
        }

        if (t.events.count("commit"))
        {
            auto commit = [&](void *data) {
                t.Commit(data);
            };
            commits.push_back(commit);
        }
    }

    template <typename T>
    void PipeTable(std::string name, T &t)
    {
        AddTableAndHandler(name, t);
    }

    void PipeInsert(std::string name, std::function<void(void *)> insert)
    {
        std::string table_name = name_ + "/tables/" + name + "/index";
        std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register<Stream>(table_name);
        inserts.insert({idx, insert});
    }

    void PipeInsert(std::string name, std::function<void(void *)> insert,
                    std::function<int64_t(void)> get_revision)
    {
        std::string table_name = name_ + "/tables/" + name + "/index";
        std::cout << "table_name = " << table_name << std::endl;
        int idx = Registrator::Register<Stream>(table_name);
        inserts.insert({idx, insert});
        revisions.insert({name, get_revision});
    }

    template <typename I, typename L>
    void AddTableAndHandlers2(std::string name, I &i, L &l)
    {
        std::string table_name = name_ + "/" + name;
        std::cout << "table_name = " << table_name << std::endl;

        int idx = Registrator::Register<Stream>(table_name);
        auto insert = [&i](void *data) {
            i.Insert(data);
        };
        auto loader = [&l](void *data, int size) {
            l.Load(data, size);
        };
        inserts.insert({idx, insert});
        loaders.insert({name, loader});
    }

    void Insert(struct cg_msg_streamdata_t &replmsg)
    {
        auto msg_index = replmsg.msg_index;

        if (inserts.count(msg_index))
        {
            //std::cout << "Insert revision:" << replmsg.rev << std::endl;
            if (revisions_filter_[msg_index] < replmsg.rev)
            {
                revisions_filter_[msg_index] = replmsg.rev;
                inserts[msg_index]((void *)replmsg.data);
            }
            else
            {
                std::cout << "discard message with revision " << replmsg.rev << std::endl;
            }
        }
    }

    void InsertData(void *msg)
    {
        struct cg_msg_data_t *replmsg = (struct cg_msg_data_t *)msg;
        auto msg_index = replmsg->msg_index;
        std::cout << "Insert Data index = " << msg_index << std::endl;
        if (inserts.count(msg_index))
        {
            std::cout << "exist for inserts , sould be updated" << std::endl;
            inserts[msg_index](msg);
        }
    }

    void SetOnline()
    {
        online_ = true;
    }

    bool IsOnline()
    {
        return online_;
    }

    void Commit()
    {
        int i = 0;
        for (auto commit : commits)
        {
            commit(NULL);
        }
    }

    void SetLifenumHandlers(std::function<void(std::string, int32_t lifenum)> lifenum_setter,
                            std::function<int32_t(std::string)> lifenum_getter)
    {
        lifenum_setter_ = lifenum_setter;
        lifenum_getter_ = lifenum_getter;
    }

    std::string GetConfig()
    {

        std::stringstream ss;
        ss << "mode=" << regime_ << ";";
        ss << "lifenum=" << GetLifenum() << ";";
        for (auto &kvp : revisions)
        {
            //get table_id
            auto table_revision = kvp.second();
            std::string table_name = name_ + "/tables/" + kvp.first + "/index";
            std::cout << "table_name = " << table_name << std::endl;
            int idx = Registrator::Register<Stream>(table_name);
            std::cout << "table_idx " << idx << std::endl;
            if (table_revision > 0)
            {
                ss << "rev." << kvp.first << "=" << table_revision + 1 << ";";
                revisions_filter_.insert({idx, table_revision});
            }
            else
            {
                revisions_filter_.insert({idx, -1});
                ss << "rev." << kvp.first << "="
                   << "0"
                   << ";";
            }
        }
        return ss.str();
    }

    int32_t GetLifenum()
    {

        if (lifenum_getter_)
        {
            //(*lifenum_getter_)(GetName());
            return lifenum_getter_(GetName());
        }
        return 0;
    }
    void SetLifenum(int32_t lifenum)
    {
        if (lifenum_setter_)
        {
            lifenum_setter_(GetName(), lifenum);
        }
    }

    template <typename T>
    std::string RestoreState(T &t)
    {
        auto repl_repr_str = t.Load(name_, loaders);
        return repl_repr_str;
    }

    CGateListener &GetListener()
    {
        return *this->lsn_;
    }

    void CloseListener()
    {
        printf("CloseListener for stream %s\n", name_.c_str());
        if (this->lsn_ != NULL)
        {
            delete this->lsn_;
        }
    }

    CGateConnection &GetConnection()
    {
        return *this->conn_;
    }

    uint32_t CheckStateIfNeededOpen()
    {
        if (lsn_)
        {
            return lsn_->CheckStateIfNeededOpen();
        }
    }

    CGateListener &GetListener(CGateConnection &conn, __stream_callback callback)
    {

        std::string stream_name = GetName();
        if (this->lsn_ != NULL)
        {
            return *lsn_;
        }
        if (stream_name == "FORTS_FUTCOMMON_REPL")
        {
            lsn_ = new CGateListener(conn,
                                     "p2repl://FORTS_FUTCOMMON_REPL;scheme=|FILE|../ini/fut_common.ini|FORTS_FUTCOMMON_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_OPTCOMMON_REPL")
        {
            lsn_ = new CGateListener(conn,
                                     "p2repl://FORTS_OPTCOMMON_REPL;scheme=|FILE|../ini/opt_common.ini|FORTS_OPTCOMMON_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_FUTINFO_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTINFO_REPL;scheme=|FILE|../ini/fut_info.ini|FORTS_FUTINFO_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_OPTINFO_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTINFO_REPL;scheme=|FILE|../ini/opt_info.ini|FORTS_OPTINFO_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_PART_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_PART_REPL;scheme=|FILE|../ini/part.ini|FORTS_PART_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_POS_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_POS_REPL;scheme=|FILE|../ini/pos.ini|FORTS_POS_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "MOEX_RATES_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://MOEX_RATES_REPL;scheme=|FILE|../ini/rates.ini|MOEX_RATES_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_FUTTRADE_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_FUTTRADE_REPL;scheme=|FILE|../ini/fut_trades.ini|FORTS_FUTTRADE_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "FORTS_OPTTRADE_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://FORTS_OPTTRADE_REPL;scheme=|FILE|../ini/opt_trades.ini|FORTS_OPTTRADE_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "MCXCC_MDCOMMON_REPL")
        {
            lsn_ = new CGateListener(conn, "p2repl://MCXCC_MDCOMMON_REPL;scheme=|FILE|../ini/mcxcc_mdcommon.ini|MCXCC_MDCOMMON_REPL",
                                     "", callback, this, [this]() { return GetConfig(); });
            conn_ = &conn;
        }
        else if (stream_name == "MESSAGE_PUB")
        {
            lsn_ = new CGateListener(conn, "p2mqreply://;ref=servlink",
                                     "", callback, this);
            conn_ = &conn;
        }
        return *lsn_;
    }

    ~Stream()
    {
        CloseListener();
        std::cout << "~Stream" << std::endl;
    }
};*/

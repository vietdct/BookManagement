#pragma once
#include <afxdb.h>

class CDatabaseManager
{
public:

    static CDatabaseManager& GetInstance();
    bool Connect();
    void Disconnect();
    CDatabase* GetDatabase();

    CDatabaseManager(const CDatabaseManager&) = delete;
    CDatabaseManager& operator=(const CDatabaseManager&) = delete;

private:
    CDatabase m_database;
    CDatabaseManager();
    ~CDatabaseManager();
    bool m_isConnected;

};
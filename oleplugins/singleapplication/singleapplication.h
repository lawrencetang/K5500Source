// "single_application.h"

#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QApplication>
#include <QSharedMemory>
#include <QStringList>
#define ACTIVE_WINDOW_TO_TOP

#ifdef ACTIVE_WINDOW_TO_TOP
typedef unsigned int    (_stdcall *TYPE_GetWindowThreadProcessId)(WId id, unsigned int *lpdwProcessId);
typedef WId             (_stdcall *TYPE_GetForegroundWindow     )();
typedef bool            (_stdcall *TYPE_SetForegroundWindow     )(WId id);
typedef WId             (_stdcall *TYPE_SetFocus                )(WId id);
typedef bool            (_stdcall *TYPE_AttachThreadInput       )(unsigned int idAttach, unsigned int idAttachTo, bool fAttach);
typedef unsigned int    (_stdcall *TYPE_GetCurrentThreadId      )();
#endif

class SingleApplication : public QApplication
{
    Q_OBJECT
public:
    SingleApplication(int &argc, char *argv[], const QString uniqueKey);

    bool alreadyExists() const{
        return bAlreadyExists;
    }
    bool isMasterApp() const{
        return !alreadyExists();
    }

    bool sendMessage(const QString &message);

public slots:
    void checkForMessage();

signals:
    void messageAvailable(const QStringList& messages);

private:
    bool bAlreadyExists;
    QSharedMemory sharedMemory;

#ifdef ACTIVE_WINDOW_TO_TOP
    TYPE_GetWindowThreadProcessId   GetWindowThreadProcessId;
    TYPE_GetForegroundWindow        GetForegroundWindow;
    TYPE_SetForegroundWindow        SetForegroundWindow;
    TYPE_SetFocus                   SetFocus;
    TYPE_AttachThreadInput          AttachThreadInput;
    TYPE_GetCurrentThreadId         GetCurrentThreadId;

    bool m_bApiVarOk;
    bool InitAPIVar();
public:
    void BringWindowToTop(WId id);
#endif
};
#endif // SINGLE_APPLICATION_H

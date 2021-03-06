#ifndef MEMMON_H
#define MEMMON_H

#include <QMainWindow>
#include <QMenu>
#include <QComboBox>
#include <QToolBar>
#include <QToolButton>

#include "mmdef.h"
#include "selectcolumndialog.h"
#include "xprocesstable/xprocesstable.h"
#include "querymanager.h"
#include "memorymonitordock.h"
#include "logoutputwindow.h"
#include "infoquerydock.h"
#include "mmuiproxy.h"
#include "mmvarproxy.h"
#include "infofetcher/cpuusagefetcher.h"
#include "infofetcher/memoryusagefetcher.h"
#include "infofetcher/processcountfetcher.h"
#include "infofetcher/servicecountfetcher.h"
#include "infofetcher/drivercountfetcher.h"
#include "infofetcher/coreusagefetcher.h"
#include "pyinfopad.h"
#include "usageinfopad.h"
#include "moduleinfodock.h"

class Memmon : public QMainWindow
{
    Q_OBJECT
public:
    explicit Memmon(QWidget *parent = 0);
    

protected:
    void closeEvent(QCloseEvent *);

private:
    void createWidgets();
    void initVars();
    void initSettings();
    void initMenus();
    void initToolbars();
    void initUsageFetcher();
    void initConnections();

    // that's where we put the late initialization variables
    void initLateInitVars();

    QAction* createAction(const QString& strText,const QIcon& icon = QIcon(), const QString& strTip = QString());
    QToolButton* createToolButton(const QString& strText,const QIcon& icon,const QString& strTip = QString());

    void showSelectColumnDialog();
    void showLogWindow();
    void showMemoryUtilityWindow();
    void showHelp();
    void showAboutThis();
    void showWMIQueryWindow();
    void showModuleInfoWindow();
    void showPopupChart();
    void configToolbar(QToolBar* toolbar);
    void populateTable();
    void showDock(QDockWidget* dock);
    void showStatus(const QString& strStatus);

    void setupStatusbar();
    void updateStatus(bool running);
    void exportContents();
    void addToInfoPad(int categoryIndex, const QByteArray& output);
    void showUsageInfoPad();
    void stopInfoFetcher(QThread* fetcher);

    void saveSettings();
    void restoreSettings();
private:
    XProcessTable* _processTable;

    SelectColumnDialog* _selectColumnDialog;
    QueryManager* _queryManager;

    MemoryMonitorDock* _mmDock;
    LogOutputWindow* _logDock;
    InfoQueryDock* _wmiQueryDock;
    ModuleInfoDock* _moduleInfoDock;

    MmUiProxy* _uiProxy;
    MmVarProxy _varProxy;

    PYInfoPad* _generalInfoPad;
    QScrollArea* _infoPadContainer;
    UsageInfoPad* _usageInfoPad;

    CpuUsageFetcher* _cpuUsageFetcher;
    MemoryUsageFetcher* _memUsageFetcher;
    ProcessCountFetcher* _processCountFetcher;
    ServiceCountFetcher* _serviceCountFetcher;
    DriverCountFetcher* _driverCountFetcher;
    CoreUsageFetcher* _coreUsageFetcher;

private Q_SLOTS:
    void slot_toolbuttonHandler();
    void slot_actionHandler();
    void slot_setColumns(const QStringList& columns);
    void slot_updateIntervalChanged(int index);
    void slot_queryStopped();
    void slot_updateCpuUsage(int usage);
    void slot_updateMemUsage(int usage);
    void slot_setTotalProcessCount(int count);
    void slot_setRunningServiceCount(int count);
    void slot_setRunningDriverCount(int count);
    void slot_showCpuUsageHistory();
    void slot_showMemUsageHistory();
    void slot_showGeneralInfo();
    void slot_addUsageWidgets();
    void slot_safeQuit();
    void slot_switchQueryEngine();
    void slot_takeSnapshot();
    void slot_find(const QString& expr);
    void slot_setDataCount(int dataCnt);
    void slot_setCurrentProcessName(const QString& processName);
    void slot_setCurrentPid(uint32_t pid);
    void slot_getProcessModuleInfo(const QString& processName);
    void slot_parseModuleInfo(const QStringList& moduleList);

    friend class MmUiProxy;

};

#endif // MEMMON_H

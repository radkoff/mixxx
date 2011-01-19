// browsefeature.h
// Created 9/8/2009 by RJ Ryan (rryan@mit.edu)

#ifndef BROWSEFEATURE_H
#define BROWSEFEATURE_H

#include <QStringListModel>
#include <QSortFilterProxyModel>

#include "configobject.h"
#include "library/browsefilter.h"
#include "library/browsetablemodel.h"
#include "library/libraryfeature.h"
#include "library/foldertreemodel.h"


class TrackCollection;

class BrowseFeature : public LibraryFeature {
    Q_OBJECT
  public:
    BrowseFeature(QObject* parent,
                  ConfigObject<ConfigValue>* pConfig,
                  TrackCollection* pTrackCollection);
    virtual ~BrowseFeature();

    QVariant title();
    QIcon getIcon();

    bool dropAccept(QUrl url);
    bool dropAcceptChild(const QModelIndex& index, QUrl url);
    bool dragMoveAccept(QUrl url);
    bool dragMoveAcceptChild(const QModelIndex& index, QUrl url);

    virtual void bindWidget(WLibrarySidebar* sidebarWidget,
                            WLibrary* libraryWidget,
                            MixxxKeyboard* keyboard);
    TreeItemModel* getChildModel();

  public slots:
    void activate();
    void activateChild(const QModelIndex& index);
    void onRightClick(const QPoint& globalPos);
    void onRightClickChild(const QPoint& globalPos, QModelIndex index);
    void searchStarting();
    void search(const QString&);
    void searchCleared();
  signals:
    void setRootIndex(const QModelIndex&);
  private:
    ConfigObject<ConfigValue>* m_pConfig;
    BrowseTableModel m_browseModel;
    BrowseFilter m_proxyModel;
    TrackCollection* m_pTrackCollection;
    FolderTreeModel m_childModel;
    QString m_currentSearch;
};

#endif /* BROWSEFEATURE_H */

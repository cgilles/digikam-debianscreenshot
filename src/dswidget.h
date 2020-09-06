/* ============================================================
 *
 * This file is a part of digiKam project
 * https://www.digikam.org
 *
 * Date        : 2010-11-29
 * Description : a tool to export images to Debian Screenshots
 *
 * Copyright (C) 2010 by Pau Garcia i Quiles <pgquiles at elpauer dot org>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#ifndef DIGIKAM_DS_WIDGET_H
#define DIGIKAM_DS_WIDGET_H

// Qt includes

#include <QWidget>
#include <QUrl>

// Local includes

#include "dactivelabel.h"
#include "ditemslist.h"
#include "dprogresswdg.h"
#include "dinfointerface.h"

class QButtonGroup;
class QNetworkReply;
class QComboBox;
class QLineEdit;

namespace KIO
{
    class AccessManager;
}

using namespace Digikam;

namespace DigikamGenericDebianScreenshotsPlugin
{

class DSWidget : public QWidget
{
    Q_OBJECT

public:

    explicit DSWidget(DInfoInterface* const iface, QWidget* const parent);
    ~DSWidget();

    DItemsList* imagesList()    const;
    DProgressWdg* progressBar() const;

Q_SIGNALS:

    void requiredPackageInfoAvailable(bool available);

private Q_SLOTS:

    void slotCompletePackageName(const QString&);
    void slotCompletePackageNameFinished(QNetworkReply*);
    void slotFindVersionsForPackage(const QString&);
    void slotFindVersionsForPackageFinished(QNetworkReply*);
    void slotEnableUpload();

private:

    QButtonGroup*       m_dlGrp;
    QString             m_lastTip;
    QUrl                m_lastQueryUrl;

    QLineEdit*          m_pkgLineEdit;
    QComboBox*          m_versionsComboBox;
    QLineEdit*          m_descriptionLineEdit;

    KIO::AccessManager* m_httpManager;
    KIO::AccessManager* m_jsonManager;

    DActiveLabel*       m_headerLabel;

    DItemsList*         m_imgList;
    DProgressWdg*       m_progressBar;

    friend class DSWindow;
};

} // namespace DigikamGenericDebianScreenshotsPlugin

#endif // DIGIKAM_DS_WIDGET_H

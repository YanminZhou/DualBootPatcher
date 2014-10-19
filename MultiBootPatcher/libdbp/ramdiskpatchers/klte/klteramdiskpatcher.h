/*
 * Copyright (C) 2014  Xiao-Long Chen <chenxiaolong@cxl.epac.to>
 *
 * This file is part of MultiBootPatcher
 *
 * MultiBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MultiBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MultiBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KLTERAMDISKPATCHER_H
#define KLTERAMDISKPATCHER_H

#include <libdbp/cpiofile.h>
#include <libdbp/patcherinterface.h>

#include <QtCore/QObject>


class KlteBaseRamdiskPatcherPrivate;

class KlteBaseRamdiskPatcher : public RamdiskPatcher
{
public:
    explicit KlteBaseRamdiskPatcher(const PatcherPaths * const pp,
                                    const FileInfo * const info,
                                    CpioFile * const cpio);
    virtual ~KlteBaseRamdiskPatcher();

    virtual PatcherError::Error error() const override;
    virtual QString errorString() const override;

    virtual QString id() const override = 0;

    virtual bool patchRamdisk() override = 0;

protected:
    const QScopedPointer<KlteBaseRamdiskPatcherPrivate> d_ptr;
    Q_DECLARE_PRIVATE(KlteBaseRamdiskPatcher)
};


class KlteAOSPRamdiskPatcher : public KlteBaseRamdiskPatcher
{
public:
    explicit KlteAOSPRamdiskPatcher(const PatcherPaths * const pp,
                                    const FileInfo * const info,
                                    CpioFile * const cpio);

    static const QString Id;

    virtual QString id() const override;

    virtual bool patchRamdisk() override;
};


class KlteTouchWizRamdiskPatcher : public KlteBaseRamdiskPatcher
{
public:
    explicit KlteTouchWizRamdiskPatcher(const PatcherPaths * const pp,
                                        const FileInfo * const info,
                                        CpioFile * const cpio);

    static const QString Id;

    virtual QString id() const override;

    virtual bool patchRamdisk() override;
};

#endif // KLTERAMDISKPATCHER_H
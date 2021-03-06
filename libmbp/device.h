/*
 * Copyright (C) 2014  Andrew Gunnerson <andrewgunnerson@gmail.com>
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

#pragma once

#include <memory>
#include <vector>

#include "libmbp_global.h"


namespace mbp
{

class MBP_EXPORT Device
{
public:
    Device();
    ~Device();

    std::string id() const;
    void setId(std::string id);
    std::vector<std::string> codenames() const;
    void setCodenames(std::vector<std::string> names);
    std::string name() const;
    void setName(std::string name);
    std::string architecture() const;
    void setArchitecture(std::string arch);
    std::vector<std::string> blockDevBaseDirs() const;
    void setBlockDevBaseDirs(std::vector<std::string> dirs);
    std::vector<std::string> systemBlockDevs() const;
    void setSystemBlockDevs(std::vector<std::string> blockDevs);
    std::vector<std::string> cacheBlockDevs() const;
    void setCacheBlockDevs(std::vector<std::string> blockDevs);
    std::vector<std::string> dataBlockDevs() const;
    void setDataBlockDevs(std::vector<std::string> blockDevs);
    std::vector<std::string> bootBlockDevs() const;
    void setBootBlockDevs(std::vector<std::string> blockDevs);
    std::vector<std::string> recoveryBlockDevs() const;
    void setRecoveryBlockDevs(std::vector<std::string> blockDevs);
    std::vector<std::string> extraBlockDevs() const;
    void setExtraBlockDevs(std::vector<std::string> blockDevs);

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

}
// Copyright 2018 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROSBAG2_STORAGE__STORAGE_INTERFACES__BASE_IO_INTERFACE_HPP_
#define ROSBAG2_STORAGE__STORAGE_INTERFACES__BASE_IO_INTERFACE_HPP_

#include <string>

#include "rosbag2_storage/visibility_control.hpp"

namespace rosbag2_storage
{
namespace storage_interfaces
{

enum class IOFlag : uint8_t
{
  READ_ONLY = 0,
  READ_WRITE = 1,
  APPEND = 2
};

class ROSBAG2_STORAGE_PUBLIC BaseIOInterface
{
public:
  virtual ~BaseIOInterface() = default;

  virtual void open(const std::string & uri, IOFlag io_flag) = 0;

  /**
   * Returns the size of the bagfile.
   * \returns the size of the bagfile in bytes.
   */
  virtual uint64_t get_bagfile_size() const = 0;
};

}  // namespace storage_interfaces
}  // namespace rosbag2_storage

#endif  // ROSBAG2_STORAGE__STORAGE_INTERFACES__BASE_IO_INTERFACE_HPP_

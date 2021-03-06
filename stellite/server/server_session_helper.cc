// Copyright 2016 LINE Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "stellite/server/server_session_helper.h"

#include "net/quic/core/crypto/quic_random.h"

namespace net {

ServerSessionHelper::ServerSessionHelper(QuicRandom* random)
    : random_(random) {
}

ServerSessionHelper::~ServerSessionHelper() {}

QuicConnectionId ServerSessionHelper::GenerateConnectionIdForReject(
    QuicConnectionId connection_id) const {
  return random_->RandUint64();
}

bool ServerSessionHelper::CanAcceptClientHello(
    const CryptoHandshakeMessage& message,
    const IPEndPoint& self_address,
    std::string* error_details) const {
  return true;
}

}  // namespace net

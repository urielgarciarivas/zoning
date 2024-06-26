/*
 * MIT License
 *
 * Copyright (c) 2024 Uriel García Rivas
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * https://github.com/zoningorg/zoning/blob/main/LICENSE
 */

#pragma once

#include <arpa/inet.h>
#include <string>
#include <unistd.h>

#include "PaqueteDatagrama.h"

class SocketDatagrama final {
 public:
  explicit SocketDatagrama() noexcept = default;
  explicit SocketDatagrama(const SocketDatagrama&) noexcept = default;

  SocketDatagrama(unsigned short puerto);
  ~SocketDatagrama() { close(socket_); }

  int recibe(PaqueteDatagrama& paquete);
  int recibe(
      PaqueteDatagrama& paquete, time_t segundos, suseconds_t microsegundos);

  int envia(const PaqueteDatagrama& paquete);

  const std::string& ip_foranea() const noexcept { return ip_foranea_; }
  auto puerto_foranea() const noexcept { return direccion_foranea_.sin_port; }

 private:
  sockaddr_in direccion_local_;
  sockaddr_in direccion_foranea_;
  timeval timeout_;
  std::string ip_foranea_;
  int socket_;
};

/*
 * MIT License
 * 
 * Copyright (c) 2021 Uriel Rivas
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * https://github.com/Garz4/zoning/blob/master/LICENSE
 */

#include <cstring>
#include <iostream>
#include <fstream>

#include "Respuesta.h"

int main(void) {
  Respuesta respuesta(7200);
  mensaje mensaje_envio;
  mensaje mensaje_recibo;

  std::ofstream archivo_guardar;
  char *archivo_recibo;

  while (1) {
    std::printf("Esperando mensaje...\n");
    std::memcpy(&mensaje_recibo, respuesta.pide(), sizeof(struct mensaje));

    if (mensaje_recibo.messageType != 'n') {
      std::printf("==================================\n");
      std::printf("%s: ", mensaje_recibo.nombreArchivo);

      archivo_recibo = new char[atoi(mensaje_recibo.tam)];
      std::memcpy(
          archivo_recibo, mensaje_recibo.archivo, atoi(mensaje_recibo.tam));
      archivo_recibo[atoi(mensaje_recibo.tam)] = '\0';
      archivo_guardar.open(mensaje_recibo.nombreArchivo);
      archivo_guardar.write(archivo_recibo, atoi(mensaje_recibo.tam));

      if (archivo_guardar.is_open()) {
        mensaje_envio.estatus = '0';
        std::printf("Guardado.\n");
      } else {
        mensaje_envio.estatus = '1';
        std::printf("Fallo en escritura.\n");
      }

      std::memcpy(
        mensaje_envio.nombreArchivo,
        mensaje_recibo.nombreArchivo,
        sizeof(mensaje_envio.nombreArchivo));

      archivo_guardar.close();
      delete[] archivo_recibo;
    }

    respuesta.responde((char *)&mensaje_envio);
  }

  return 0;
}

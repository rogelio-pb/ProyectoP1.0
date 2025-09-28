#pragma once
#include "Prerequisites.h"



class Ticket {
private:
    int ID;
    std::string titulo;
    std::string descripcion;
    std::string estado; // Pendiente, En Proceso, Completado
    std::string fechaC;

public:
    // Constructor con fecha opcional
    Ticket
        (int id, const std::string& title, const std::string& desc,
         ESTADO est = PENDIENTE, const std::string& fecha = "")
        : ID(id), titulo(title), descripcion(desc) {
        fechaC = fecha.empty() ? "Fecha no asignada" : fecha;
        switch (est) {
        case PENDIENTE: estado = "Pendiente"; break;
        case EN_PROCESO: estado = "En Proceso"; break;
        case COMPLETADO: estado = "Completado"; break;
        }
    }

    int getID() const { return ID; }
    std::string getTitulo() const { return titulo; }
    std::string getDescripcion() const { return descripcion; }
    std::string getEstado() const { return estado; }
    std::string getFecha() const { return fechaC; }

    void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
    void setDescripcion(const std::string& nuevaD) { descripcion = nuevaD; }

    // Cambiar estado con validación de transición
    bool cambioEstado(ESTADO nuevoEstado) {
        if (nuevoEstado == PENDIENTE) {
            estado = "Pendiente"; return true;
        }
        else if (nuevoEstado == EN_PROCESO && estado == "Pendiente") {
            estado = "En Proceso"; return true;
        }
        else if (nuevoEstado == COMPLETADO && estado == "En Proceso") {
            estado = "Completado"; return true;
        }
        std::cout << "Transicion de estado no valida.\n";
        return false;
    }

    void mostrar() const {
        std::cout << "ID: " << ID
            << "  Titulo: " << titulo
            << "  Descripcion: " << descripcion
            << "  Estado: " << estado
            << "  Fecha: " << fechaC << std::endl;
    }
};

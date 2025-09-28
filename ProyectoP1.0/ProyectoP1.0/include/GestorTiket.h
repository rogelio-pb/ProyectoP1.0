#pragma once
#include"Prerequisites.h"
#include "Tiket.h"


class GestorTicket {
private:
	std::vector<Ticket> tickets;// Almacena los tickets que se van creando
    int contadorID = 0; // Para asignar IDs únicos

    std::string obtenerFechaActual() {
        time_t now = time(0);
        std::string fecha = ctime(&now);
        fecha.pop_back(); // quitar salto de linea
        return fecha;
    }

public:
    void crearTicket(const std::string& titulo, const std::string& descripcion) {
        contadorID++;
        tickets.emplace_back(contadorID, titulo, descripcion, PENDIENTE, obtenerFechaActual());
        std::cout << "Ticket creado con ID: " << contadorID << std::endl;
    }

    void eliminarTicket(int id) {
        auto it = std::remove_if(tickets.begin(), tickets.end(),
            [id](const Ticket& t) { return t.getID() == id; });

        if (it != tickets.end()) {
            tickets.erase(it, tickets.end());
            std::cout << "Ticket con ID " << id << " eliminado.\n";
        }
        else {
            std::cout << "Ticket con ID " << id << " no encontrado.\n";
        }
    }

    void editarTicket(int id, const std::string& nuevoTitulo, const std::string& nuevaDescripcion) {
        for (auto& t : tickets) {
            if (t.getID() == id) {
                t.setTitulo(nuevoTitulo);
                t.setDescripcion(nuevaDescripcion);
                std::cout << "Ticket ID " << id << " editado.\n";
                return;
            }
        }
        std::cout << "Ticket con ID " << id << " no encontrado.\n";
    }

    void cambiarEstadoTicket(int id, ESTADO nuevoEstado) {
        for (auto& t : tickets) {
            if (t.getID() == id) {
                t.cambioEstado(nuevoEstado);
                return;
            }
        }
        std::cout << "Ticket con ID " << id << " no encontrado.\n";
    }

    void listarTickets() const {
        if (tickets.empty()) {
            std::cout << "No hay tickets registrados.\n";
            return;
        }
        for (const auto& t : tickets) {
            t.mostrar();
        }
    }
};

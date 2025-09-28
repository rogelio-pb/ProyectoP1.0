#pragma once
#include"Prerequisites.h"
#include "Tiket.h"


class GestorTicket {
private:
	std::vector<Ticket> tickets;// Almacena los tickets que se van creando
    int contadorID = 0; // Para asignar IDs únicos

	std::string obtenerFechaActual() {// Obtener la fecha actual como string
		time_t now = time(0);// obtener tiempo actual
		std::string fecha = ctime(&now);// convertir a string
        fecha.pop_back(); // quitar salto de linea
		return fecha;   // devolver fecha
    }

public:// Metodos para gestionar los tickets
	void crearTicket(const std::string& titulo, const std::string& descripcion) {// Crear un nuevo ticket y agregarlo al vector de tickets
	contadorID++;// Incrementar el contador de ID único 
	tickets.emplace_back(contadorID, titulo, descripcion, PENDIENTE, obtenerFechaActual());// Crear y agregar el ticket al vector de tickets y asignar la fecha actual al ticket al crearlo
	std::cout << "Ticket creado con ID: " << contadorID << std::endl;// Confirmar la creación del ticket de forma exitosa y mostrar su ID 
    }
                                                                                          
	void eliminarTicket(int id) {// Eliminar un ticket por su ID y mostrar mensaje de confirmación
		auto it = std::remove_if(tickets.begin(), tickets.end(), // Buscar el ticket por su ID con std::remove_if 
			[id](const Ticket& t) { return t.getID() == id; }); // aqui se usa una lambda para comparar el ID del ticket con el ID proporcionado y ver si es igual

        if (it != tickets.end()) {
            tickets.erase(it, tickets.end());
            std::cout << "Ticket con ID " << id << " eliminado.\n";
        }
        else {
            std::cout << "Ticket con ID " << id << " no encontrado.\n";
        }
    }

void editarTicket(int id,const std::string& nuevoTitulo,const std::string& nuevaD) 
    {
        for (auto& t : tickets) {
            if (t.getID() == id) {
                t.setTitulo(nuevoTitulo);
                t.setDescripcion(nuevaD);
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

#pragma once
#include"Prerequisites.h"
#include "Tiket.h"


class GestorTicket {
private:
	std::vector<Ticket> tickets;// Almacena los tickets que se van creando
    int contadorID = 0; // Para asignar IDs �nicos

	std::string obtenerFechaActual() {// Obtener la fecha actual como string
		time_t now = time(0);// obtener tiempo actual
		std::string fecha = ctime(&now);// convertir a string
        fecha.pop_back(); // quitar salto de linea
		return fecha;   // devolver fecha
    }

public:// Metodos para gestionar los tickets
	void crearTicket(const std::string& titulo, const std::string& descripcion) {// Crear un nuevo ticket y agregarlo al vector de tickets
	contadorID++;// Incrementar el contador de ID �nico 
	tickets.emplace_back(contadorID, titulo, descripcion, PENDIENTE, obtenerFechaActual());// Crear y agregar el ticket al vector de tickets y asignar la fecha actual al ticket al crearlo
	std::cout << "Ticket creado con ID: " << contadorID << std::endl;// Confirmar la creaci�n del ticket de forma exitosa y mostrar su ID 
    }
                                                                                          
	void eliminarTicket(int id) {// Eliminar un ticket por su ID y mostrar mensaje de confirmaci�n
		auto it = std::remove_if(tickets.begin(), tickets.end(), // Buscar el ticket por su ID con std::remove_if 
			[id](const Ticket& t) { return t.getID() == id; }); // aqui se usa una lambda para comparar el ID del ticket con el ID proporcionado y ver si es igual

		if (it != tickets.end()) {// Si se encontr� el ticket, eliminarlo y mostrar mensaje de confirmaci�n
			tickets.erase(it, tickets.end());// Eliminar el ticket del vector de tickets 
			std::cout << "Ticket con ID " << id << " eliminado.\n";// Confirmar la eliminaci�n del ticket 
        }
		else {// Si no se encontr� el ticket, mostrar mensaje de error
			std::cout << "Ticket con ID " << id << " no encontrado.\n";// Mensaje de error si no se encuentra el ticket
        }
    }

	void editarTicket(int id, const std::string& nuevoTitulo, const std::string& nuevaD) // Editar el t�tulo y la descripci�n de un ticket por su ID
    {
		for (auto& t : tickets) {// Recorrer el vector de tickets en bucle hasta encontrar el ticket con el ID proporcionado
			if (t.getID() == id) {// Si se encuentra el ticket con el ID proporcionado, actualizar su t�tulo y descripci�n
				t.setTitulo(nuevoTitulo);// Actualizar el t�tulo del ticket
				t.setDescripcion(nuevaD);// Actualizar la descripci�n del ticket
				std::cout << "Ticket ID " << id << " editado.\n";// Confirmar la edici�n del ticket
				return;// Salir de la funci�n despu�s de editar el ticket   
            }
        }
		std::cout << "Ticket con ID " << id << " no encontrado.\n";// Mensaje de error si no se encuentra el ticket
    }

	void cambiarEstadoTicket(int id, ESTADO nuevoEstado) {// Cambiar el estado de un ticket por su ID donde busca el ticket por su ID y llama al m�todo cambioEstado del ticket
		for (auto& t : tickets) {// Recorrer el vector de tickets en bucle hasta encontrar el ticket con el ID proporcionado
			if (t.getID() == id) {// Si se encuentra el ticket con el ID proporcionado, intentar cambiar su estado
				t.cambioEstado(nuevoEstado);// Intentar cambiar el estado del ticket en clase Ticket
				return;// Salir de la funci�n despu�s de intentar cambiar el estado del ticket
            }
        }
		std::cout << "Ticket con ID " << id << " no encontrado.\n";// Mensaje de error si no se encuentra el ticket
    }

	void listarTickets() const {// Listar todos los tickets almacenados en el vector de tickets
		if (tickets.empty()) {// Si no hay tickets, mostrar mensaje
			std::cout << "No hay tickets registrados.\n";//Mensaje si no hay tickets
			return;// Salir de la funci�n si no hay tickets
        }
		for (const auto& t : tickets) {// Recorrer el vector de tickets y mostrar cada ticket
			t.mostrar();// Mostrar el ticket actual
		}// Fin del bucle for
	}// Fin de la clase GestorTicket
};// Fin del archivo GestorTiket.h

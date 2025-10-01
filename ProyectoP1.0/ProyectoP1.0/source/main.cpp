#include"Prerequisites.h"
#include "GestorTiket.h"

int main() {// Funci�n principal del programa
	GestorTicket gestor;// Crear una instancia del gestor de tickets
	int opcion;// Variable para almacenar la opci�n del men�

    do {
		std::cout << "\n--- Menu de Gestion de Tickets ---\n";// Mostrar el men� de opciones
        std::cout << "1. Crear Ticket\n";
        std::cout << "2. Eliminar Ticket\n";
        std::cout << "3. Editar Ticket\n";
        std::cout << "4. Cambiar Estado\n";
        std::cout << "5. Listar Tickets\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;// Leer la opci�n del usuario
		std::cin.ignore(); // limpiar buffer de entrada

		switch (opcion) {// Manejar la opci�n seleccionada
		case 1: {// Crear un nuevo ticket
			std::string titulo, descripcion;// Variables para el t�tulo y la descripci�n del ticket
			std::cout << "Titulo: ";// Pedir el t�tulo del ticket
			std::getline(std::cin, titulo);// Leer el t�tulo del ticket
			std::cout << "Descripcion: ";// Pedir la descripci�n del ticket
			std::getline(std::cin, descripcion);// Leer la descripci�n del ticket
			gestor.crearTicket(titulo, descripcion);// Llamar al m�todo para crear el ticket en el gestor
            break;
        }
        case 2: {
			int id;// Variable para el ID del ticket a eliminar
			std::cout << "ID del ticket a eliminar: ";// Pedir el ID del ticket a eliminar
			std::cin >> id;// Leer el ID del ticket a eliminar
			gestor.eliminarTicket(id);// Llamar al m�todo para eliminar el ticket en el gestor
            break;
        }
		case 3: {// Editar un ticket existente
            int id;
			std::string titulo, descripcion;// Variables para el ID, t�tulo y descripci�n del ticket a editar
			std::cout << "ID del ticket a editar: ";// Pedir el ID del ticket a editar
			std::cin >> id;// Leer el ID del ticket a editar
			std::cin.ignore();// limpiar buffer de entrada
			std::cout << "Nuevo titulo: ";// Pedir el nuevo t�tulo del ticket
			std::getline(std::cin, titulo);// Leer el nuevo t�tulo del ticket
			std::cout << "Nueva descripcion: ";// Pedir la nueva descripci�n del ticket
			std::getline(std::cin, descripcion);// Leer la nueva descripci�n del ticket
			gestor.editarTicket(id, titulo, descripcion);// Llamar al m�todo para editar el ticket en el gestor
            break;
        }
		case 4: {// Cambiar el estado de un ticket
			int id, est;// Variables para el ID y el nuevo estado del ticket
			std::cout << "ID del ticket: ";// Pedir el ID del ticket
			std::cin >> id;// Leer el ID del ticket
			std::cout << "Nuevo estado (0=Pendiente, 1=En Proceso, 2=Completado): ";// Pedir el nuevo estado del ticket
			std::cin >> est;// Leer el nuevo estado del ticket
			gestor.cambiarEstadoTicket(id, static_cast<ESTADO>(est));// Llamar al m�todo para cambiar el estado del ticket en el gestor
            break;
        }
		case 5:// Listar todos los tickets
			gestor.listarTickets();// Llamar al m�todo para listar los tickets en el gestor
            break;
		case 6:// Salir del programa
			std::cout << "Saliendo...\n";// Mensaje de salida
            break;
        default:
			std::cout << "Opcion no valida.\n";// Mensaje de opci�n no v�lida
        }

	} while (opcion != 6);// Repetir el men� hasta que el usuario elija salir

    return 0;
}
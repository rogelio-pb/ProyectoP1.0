#include"Prerequisites.h"
#include "GestorTiket.h"

int main() {// Función principal del programa
	GestorTicket gestor;// Crear una instancia del gestor de tickets
	int opcion;// Variable para almacenar la opción del menú

    do {
		std::cout << "\n--- Menu de Gestion de Tickets ---\n";// Mostrar el menú de opciones
        std::cout << "1. Crear Ticket\n";
        std::cout << "2. Eliminar Ticket\n";
        std::cout << "3. Editar Ticket\n";
        std::cout << "4. Cambiar Estado\n";
        std::cout << "5. Listar Tickets\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;// Leer la opción del usuario
		std::cin.ignore(); // limpiar buffer de entrada

		switch (opcion) {// Manejar la opción seleccionada
		case 1: {// Crear un nuevo ticket
			std::string titulo, descripcion;// Variables para el título y la descripción del ticket
			std::cout << "Titulo: ";// Pedir el título del ticket
			std::getline(std::cin, titulo);// Leer el título del ticket
			std::cout << "Descripcion: ";// Pedir la descripción del ticket
			std::getline(std::cin, descripcion);// Leer la descripción del ticket
			gestor.crearTicket(titulo, descripcion);// Llamar al método para crear el ticket en el gestor
            break;
        }
        case 2: {
			int id;// Variable para el ID del ticket a eliminar
			std::cout << "ID del ticket a eliminar: ";// Pedir el ID del ticket a eliminar
			std::cin >> id;// Leer el ID del ticket a eliminar
			gestor.eliminarTicket(id);// Llamar al método para eliminar el ticket en el gestor
            break;
        }
		case 3: {// Editar un ticket existente
            int id;
			std::string titulo, descripcion;// Variables para el ID, título y descripción del ticket a editar
			std::cout << "ID del ticket a editar: ";// Pedir el ID del ticket a editar
			std::cin >> id;// Leer el ID del ticket a editar
			std::cin.ignore();// limpiar buffer de entrada
			std::cout << "Nuevo titulo: ";// Pedir el nuevo título del ticket
			std::getline(std::cin, titulo);// Leer el nuevo título del ticket
			std::cout << "Nueva descripcion: ";// Pedir la nueva descripción del ticket
			std::getline(std::cin, descripcion);// Leer la nueva descripción del ticket
			gestor.editarTicket(id, titulo, descripcion);// Llamar al método para editar el ticket en el gestor
            break;
        }
		case 4: {// Cambiar el estado de un ticket
			int id, est;// Variables para el ID y el nuevo estado del ticket
			std::cout << "ID del ticket: ";// Pedir el ID del ticket
			std::cin >> id;// Leer el ID del ticket
			std::cout << "Nuevo estado (0=Pendiente, 1=En Proceso, 2=Completado): ";// Pedir el nuevo estado del ticket
			std::cin >> est;// Leer el nuevo estado del ticket
			gestor.cambiarEstadoTicket(id, static_cast<ESTADO>(est));// Llamar al método para cambiar el estado del ticket en el gestor
            break;
        }
		case 5:// Listar todos los tickets
			gestor.listarTickets();// Llamar al método para listar los tickets en el gestor
            break;
		case 6:// Salir del programa
			std::cout << "Saliendo...\n";// Mensaje de salida
            break;
        default:
			std::cout << "Opcion no valida.\n";// Mensaje de opción no válida
        }

	} while (opcion != 6);// Repetir el menú hasta que el usuario elija salir

    return 0;
}
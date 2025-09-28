#include"Prerequisites.h"
#include "GestorTiket.h"

int main() {
    GestorTicket gestor;
    int opcion;

    do {
        std::cout << "\n--- Menu de Gestion de Tickets ---\n";
        std::cout << "1. Crear Ticket\n";
        std::cout << "2. Eliminar Ticket\n";
        std::cout << "3. Editar Ticket\n";
        std::cout << "4. Cambiar Estado\n";
        std::cout << "5. Listar Tickets\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer

        switch (opcion) {
        case 1: {
            std::string titulo, descripcion;
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Descripcion: ";
            std::getline(std::cin, descripcion);
            gestor.crearTicket(titulo, descripcion);
            break;
        }
        case 2: {
            int id;
            std::cout << "ID del ticket a eliminar: ";
            std::cin >> id;
            gestor.eliminarTicket(id);
            break;
        }
        case 3: {
            int id;
            std::string titulo, descripcion;
            std::cout << "ID del ticket a editar: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Nuevo titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Nueva descripcion: ";
            std::getline(std::cin, descripcion);
            gestor.editarTicket(id, titulo, descripcion);
            break;
        }
        case 4: {
            int id, est;
            std::cout << "ID del ticket: ";
            std::cin >> id;
            std::cout << "Nuevo estado (0=Pendiente, 1=En Proceso, 2=Completado): ";
            std::cin >> est;
            gestor.cambiarEstadoTicket(id, static_cast<ESTADO>(est));
            break;
        }
        case 5:
            gestor.listarTickets();
            break;
        case 6:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opcion no valida.\n";
        }

    } while (opcion != 6);

    return 0;
}
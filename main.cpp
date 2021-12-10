
/**
 * archivos '.h' son archivos de cabecera**
 * Include cirver para traer codigo de otros archivos**
 * Este include trae todas las liberias y archivos para un mejor ordenamiento
 */
#include ".h/ordenar.h"

int main()
{
    string operacion = "1";
    imprimir Obj1;

    do
    {
        // cambio de color para estetica*
        system("color a");
        cout << "--------------------------\n";
        cout << "ingresa una operacion: \n"; // mensaje al usuario*
        fflush(stdin);                       // liveracion del bufer para el correcto funcionamiento.*
        getline(cin, operacion);             // obtencion de la operacion a resolver*

        // Comprobacion para entrar o salir del programa*
        if (operacion.compare("1") != 0)
        {
            if (operacion.size() < 100)
            {

                if (operacion.compare("") != 0)
                {
                    // reconstruye la clase para poder usar otros valores en la operacion
                    Obj1 = imprimir(operacion);
                    Obj1.Obtener_Resultado();
                }
                else
                    system("cls");
            }
            else
            {
                // Mensaje de error por sobrepasar la cantidad de caracteres permitidos.*
                system("cls");
                system("color 0c");
                cout << "--------------------------";
                cout << "has escrito mas de 100 caracteres.\n    No. caracteres: " << operacion.size() << endl;
                cout << "    Dicho numero de caracteres estan por fuera de lo permitido, favor de intentarlo de nuevo" << endl;
                system("pause");
                system("cls");
            }
        }
        else
        {
            // mensaje Final de agradesimiento por usar la calculadora
            system("cls");
            cout << "--------------------------";
            cout << "\n    Gracias por usar esta calculadora\n\n";
        }
    } while (operacion.compare("1") != 0);

    system("pause");
}



separar::separar(string _operacion)
{
    operacion = _operacion;
    iteradorNumerico = 0;
    IteradorOperadores = 0;
}

void separar::ordenamiento(void)
{
    string concatenar = "", caracter;

    for (int j = 0; j < operacion.size(); j++)
    {
        caracter = operacion[j];
        if (caracter.compare("+") == 0)
        {
            numerosStr[iteradorNumerico] = concatenar;
            concatenar = "", operadores[iteradorNumerico] = 's';
            iteradorNumerico++;
            IteradorOperadores++;
        }

        else if (caracter.compare("-") == 0)
        {
            numerosStr[iteradorNumerico] = concatenar;
            concatenar = "", operadores[iteradorNumerico] = 'r';
            iteradorNumerico++;
            IteradorOperadores++;
        }

        else if (caracter.compare("/") == 0)
        {
            numerosStr[iteradorNumerico] = concatenar;
            concatenar = "";
            operadores[iteradorNumerico] = 'd';
            iteradorNumerico++;
            IteradorOperadores++;
        }

        else if (caracter.compare("*") == 0)
        {
            numerosStr[iteradorNumerico] = concatenar;
            concatenar = "";
            operadores[iteradorNumerico] = 'm';
            iteradorNumerico++;
            IteradorOperadores++;
        }


        else if (caracter.compare("(") == 0)
        {
            operadores[iteradorNumerico] = 'i';

            if (concatenar.compare("") == 0) numerosStr[iteradorNumerico] = "1";
            else numerosStr[iteradorNumerico] = concatenar;

            concatenar = "";
            iteradorNumerico++;
            IteradorOperadores++;
        }

        else if (caracter.compare(")") == 0)
        {
            operadores[iteradorNumerico] = 'f';

            if (concatenar.compare("") == 0) numerosStr[iteradorNumerico] = "1";
            else numerosStr[iteradorNumerico] = concatenar;

            concatenar = "";
            iteradorNumerico++;
            IteradorOperadores++;
        }

        else concatenar += operacion[j];
    }


    if (concatenar.compare("") != 0)
    {
        numerosStr[iteradorNumerico] = concatenar;
        iteradorNumerico++;
    }

    concatenar = operacion[operacion.size() - 1];

    if (concatenar.compare("=") == 0) final = true;
}
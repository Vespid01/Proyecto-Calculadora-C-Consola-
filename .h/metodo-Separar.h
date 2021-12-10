
// contructor de la clase separar y obtension de la operacion a realizar**
separar::separar(string _operacion)
{
    operacion = _operacion;
    iteradorNumerico = 0;
    IteradorOperadores = 0;
}


// este metodo separa los numeros y operadores**
void separar::ordenamiento(void)
{
    string concatenar = "", caracter;

    for (int i = 0; i < operacion.size(); i++)
    {
        caracter = operacion[i];

        if      (caracter.compare("+") == 0){ numerosStr[iteradorNumerico] = concatenar;concatenar = "", operadores[IteradorOperadores] = 's'; iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("-") == 0){ numerosStr[iteradorNumerico] = concatenar;concatenar = "", operadores[IteradorOperadores] = 'r'; iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("/") == 0){ numerosStr[iteradorNumerico] = concatenar;concatenar = ""; operadores[IteradorOperadores] = 'd'; iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare("*") == 0){ numerosStr[iteradorNumerico] = concatenar;concatenar = ""; operadores[IteradorOperadores] = 'm'; iteradorNumerico++;IteradorOperadores++;}

        else if (caracter.compare("(") == 0){operadores[IteradorOperadores] = 'i'; if (concatenar.compare("") == 0) numerosStr[iteradorNumerico] = "1"; else numerosStr[iteradorNumerico] = concatenar; concatenar = "";iteradorNumerico++;IteradorOperadores++;}
        else if (caracter.compare(")") == 0){operadores[IteradorOperadores] = 'f'; numerosStr[iteradorNumerico] = concatenar; concatenar = "";iteradorNumerico++;IteradorOperadores++;}

        else concatenar += operacion[i];
    }
    // este if detecta si hay un ultimo valor el cual agregar para poder hacer la operacion completa*
    if (concatenar.compare("") != 0){ numerosStr[iteradorNumerico] = concatenar;iteradorNumerico++;}
    
    // estas 2 lineas detectan si hay un signo de = al final, para agregarlo en la impresion y no se repita*
    concatenar = operacion[operacion.size()-1];

    if(concatenar.compare("=")==0) final = true;
}
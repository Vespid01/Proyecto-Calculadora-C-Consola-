
// clase separar, esta clase tiene el metodo que separa los operadores y numeros de la operacion ingresada
class separar
{
    protected:
        string operacion, numerosStr[50]; 
        bool   final;
        char   operadores[50];
        int    iteradorNumerico, IteradorOperadores;

        void ordenamiento(void);

    public:
        separar  (string _operacion = "1");
        ~separar (void) {}
};
/**
 * Esta clase 'operar' esta clase hereda metodos de la clase 'separar'
 * esta clase obtiene los datos de la anterior clase y luego hace lo sigiente:
 *          
 *          combierte los numeros de string a Float
 *          Ordena los datos para si corresto funcionamiento
 *          Usa un algoritmo que revisa si hay un un parentesis y si sí lo resuelve antes que cualquier cosa
 *          Usa un algoritmo que usa el metodo 'moveratrasS' para resolver primero todas las multiplicasiones
 *          Usa un algoritmo que usa el metodo 'moveratrasS' para resolver primero todas las division
 *          Usa un algoritmo que usa el metodo 'moveratrasS' para resolver primero todas las Sumas y restas
 *          Usa el cosntructor que manda la operacion ingresada a la clase 'separar'
 *  
 *          La funcion IA usa todos los metodos y los ordena para el funcionamiento del programa (funjiendo como cerebro)
 *  
 */
class operar : public separar
{
    protected:
        float numerosArray[50]; 
        
        void comvercion      (void);

        void moveratrasS     (int _PosisionInicial);

        void parentesis      (int _posisionInicial);
        void multiplicasionD (int _posisionInicial, int _posisionFinal);
        void divicion        (int _posisionInicial, int _posisionFinal);
        void sumaR           (int _posisionInicial, int _posisionFinal);

    public:
        operar   (string _operacion = "1");
        float IA (void);
        ~operar  (void) {}
};


//esta clase solo obtene los metodos y etc de anteriores clases he imprime el resultado de una forma amigable al usuario
class imprimir : public operar
{
    public:
        imprimir               (string _operacion = "1");
        void Obtener_Resultado (void);
        ~imprimir              (void) {}
};

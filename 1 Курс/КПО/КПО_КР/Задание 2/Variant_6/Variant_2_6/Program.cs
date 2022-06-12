Triangle ABC = new Triangle();
int upOrDown = 1;

Console.Write("Введите сторону треугольника \nВвод: ");
ABC.A = Convert.ToDouble(Console.ReadLine());
Console.Write("Введите два угола придежащих к стороне \nВвод: ");
ABC.ANGLB = Convert.ToDouble(Console.ReadLine());
Console.Write("Ввод: ");
ABC.ANGLC = Convert.ToDouble(Console.ReadLine());


Console.WriteLine("\nУвеличение или уменьшение угола:\n1)Увеличение угла Бета\n2)Увеличение угла Гамма\n3)Уменьшение угла Бета\n4)Уменьшение угла Гамма\n0)Выход");


while (upOrDown != 0) 
{
Console.Write("\nВвод: ");
upOrDown = Convert.ToInt32(Console.ReadLine());
    if (upOrDown == 0)
    {
        continue;
    }
Console.Write("Ведите колличество процентов: ");
int valueUpOrDown = Convert.ToInt32(Console.ReadLine());
switch (upOrDown)
{
    case 1:
        Console.WriteLine("Угол Бета = {0}", ABC.upAnglB(valueUpOrDown));
        break;
    case 2:
        Console.WriteLine("Угол Гамма = {0}", ABC.upAnglC(valueUpOrDown));
        break;
    case 3:
        Console.WriteLine("Угол Бета = {0}", ABC.downAnglB(valueUpOrDown));
        break;
    case 4:
        Console.WriteLine("Угол Гамма= {0}", ABC.downAnglC(valueUpOrDown));
        break;
    default:
        Console.WriteLine("default");
        break;
}
}

double alpha = ABC.Alpha(ABC.ANGLB, ABC.ANGLC);
double sideB = ABC.sideB(ABC.A, ABC.ANGLB, alpha);
double sideC = ABC.sideC(ABC.A, ABC.ANGLC, alpha);

Console.WriteLine("\nЗначение высоты сторон:\nДлинна высоты А = {0}", Convert.ToInt32(ABC.height(ABC.A, sideB, sideC, ABC.A)));
Console.WriteLine("Длинна высоты B = {0}", Convert.ToInt32(ABC.height(ABC.A, sideB, sideC, sideB)));
Console.WriteLine("Длинна высоты С = {0}", Convert.ToInt32(ABC.height(ABC.A, sideB, sideC, sideC)));

Console.WriteLine("\nЗначение сторон:\nА = {0}", Convert.ToInt32(ABC.A));
Console.WriteLine("B = {0}", Convert.ToInt32(sideB));
Console.WriteLine("C = {0}", Convert.ToInt32(sideC)); 




class Triangle
{
    private double a, anglB, anglC;
    public double A
    {
        get { return a; } 
        set { a = value; }  
    }
    public double ANGLB
    {
        get { return anglB; } 
        set { anglB = value; }  
    }
    public double ANGLC
    {
        get { return anglC; } 
        set { anglC = value; }  
    }
    public Triangle(Triangle Triangle)
    {
        a = Triangle.a;
        anglB = Triangle.anglB;
        anglC = Triangle.anglC;
    }
    public Triangle(double a, double anglB, double anglC)
    {
        this.a = a;
        this.anglB = anglB;
        this.anglC = anglC;
    }
    public Triangle()
    {
        a = 0;
        anglB = 0;
        anglC = 0;
    }
    public override string ToString()
    {
        return "\r\n" + base.ToString() + "\r\n" + "1 сторона = " + a + "\r\n" + "1 угол = " + anglB + "\r\n" + "2 угол = " + anglC;
    }
    public double upAnglB(double p)
    {
        return this.anglB = (anglB + (anglB * (p / 100)));
    }
    public double upAnglC(double p)
    {
        return this.anglC = (anglC + (anglC * (p / 100)));
    }
    public double downAnglB(double p)
    {
        return this.anglB = (anglC - (anglC * (p / 100)));
    }
    public double downAnglC(double p)
    {
        return this.anglC = (anglC - (anglC * (p / 100)));
    }
    public double valueC(double a, double b, double anglAB)
    {
        return Math.Sqrt((a * a) + (b * b) - ((2 * a * b) * Math.Cos(Math.PI * anglAB / 180.0)));
    }
    public double Alpha(double Beta, double Gamma)
    {
        double x = 180;
        return (x - (Beta + Gamma));
    }
    public double sideB(double a, double beta, double alpha)
    {
        return (a * Math.Sin(Math.PI * beta / 180.0))/ Math.Sin(Math.PI * alpha / 180.0);
    }
    public double sideC(double a, double gamma, double alpha)
    {
        return (a * Math.Sin(Math.PI * gamma / 180.0)) / Math.Sin(Math.PI * alpha / 180.0);
    }
    public double height(double a, double b, double c, double lineFind)
    {
        double p = ((a + b + c) / 2);
        double h = (2 * Math.Sqrt(p * (p - a) * (p - b) * (p - c)))/ lineFind;
        return h;
    }
}

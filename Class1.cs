using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR7
{
    class Rational : IComparable<Rational>, IConvertible
    {
        private long numerator;
        public long Numerator
        {
            get
            {
                return numerator;
            }
            set
            {
                numerator = value;
                if (denominator != 0 && numerator != 0)
                {
                    long gcd = GCD(Math.Abs(denominator), numerator);
                    denominator /= gcd;
                    numerator /= gcd;
                }
            }
        }
        private long denominator;
        public long Denominator
        {
            get
            {
                return denominator;
            }
            set
            {
                if (denominator == 0)
                {
                    throw new ArgumentException("Denominator can't be zero\n");
                }
                denominator = value;
                if (numerator != 0)
                {
                    long gcd = GCD(Math.Abs(denominator), numerator);
                    denominator /= gcd;
                    numerator /= gcd;
                }
            }
        }
        public Rational(long numerator, long denominator)
        {
            this.numerator = numerator;
            this.denominator = denominator;
            Numerator = this.numerator;
            Denominator = this.denominator;
        }
        public Rational(long numerator)
        {
            denominator = 1;
            Numerator = numerator;
            Denominator = 1;
        }
        private static long GCD(long a, long b)
        {
            if (a > b)
            {
                (a, b) = (b, a);
            }
            while (b != 0)
            {
                a %= b;
                (a, b) = (b, a);
            }
            return a;
        }
        public override string ToString()
        {
            return ToString("F");
        }
        public string ToString(string format)
        {
            return ToString(format, null);
        }
        public string ToString(string format, IFormatProvider provider)
        {
            if (string.IsNullOrEmpty(format))
            {
                format = "F";
            }
            if (format == "IF")
            {
                if (Math.Abs(numerator) > denominator && denominator != 1)
                {
                    long integral = numerator / denominator;
                    return $"{integral}({Math.Abs(numerator) % denominator}/{denominator})";
                }
                else
                {
                    format = "I";
                }
            }
            if (format == "I")
            {
                if (Math.Abs(numerator) > denominator)
                {
                    long integral = numerator / denominator;
                    return integral.ToString();
                }
                else
                {
                    format = "F";
                }
            }
            if (format == "F")
            {
                return $"{numerator}/{denominator}";
            }
            else if (format == "D")
            {
                return GetDoubleValue().ToString();
            }
            else
            {
                throw new FormatException($"The \"{format}\" format is not supported.");
            }
        }
        double GetDoubleValue()
        {
            return (double)numerator / denominator;
        }
        public int CompareTo(Rational fraction)
        {
            long lcm = denominator * fraction.Denominator /
                       GCD(Math.Abs(denominator), fraction.Denominator);

            long n1 = numerator * (lcm / denominator);
            long n2 = fraction.Numerator * (lcm / fraction.Denominator);
            if (n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
            return 0;
        }
        public static bool operator >(Rational a, Rational b)
        {
            return a.CompareTo(b) == 1;
        }
        public static bool operator <(Rational a, Rational b)
        {
            return a.CompareTo(b) == -1;
        }
        public static bool operator >=(Rational a, Rational b)
        {
            return a.CompareTo(b) != -1;
        }
        public static bool operator <=(Rational a, Rational b)
        {
            return a.CompareTo(b) != 1;
        }
        public static bool operator ==(Rational a, Rational b)
        {
            return a.CompareTo(b) == 0;
        }
        public static bool operator !=(Rational a, Rational b)
        {
            return a.CompareTo(b) != 0;
        }
        public static Rational operator +(Rational a, Rational b)
        {
            long lcm = a.Denominator * b.Denominator /
                      GCD(Math.Abs(a.Denominator), Math.Abs(b.Denominator));

            long n1 = a.Numerator * (lcm / a.Denominator);
            long n2 = b.Numerator * (lcm / b.Denominator);
            return new Rational(n1 + n2, lcm);
        }
        public static Rational operator -(Rational a)
        {
            return a * -1;
        }
        public static Rational operator -(Rational a, Rational b)
        {
            return a + (-b);
        }
        public static Rational operator *(Rational a, long b)
        {
            return new Rational(a.Numerator * b, a.Denominator);
        }
        public static Rational operator *(Rational a, Rational b)
        {
            return new Rational(a.Numerator * b.Numerator, a.Denominator * b.Denominator);
        }
        public static Rational operator /(Rational a, Rational b)
        {
            return new Rational(a.Numerator * b.Denominator, a.Denominator * b.Numerator);
        }
        public static explicit operator int(Rational f)
        {
            return f.ToInt32(null);
        }
        public static explicit operator long(Rational f)
        {
            return f.ToInt64(null);
        }
        public static explicit operator float(Rational f)
        {
            return f.ToSingle(null);
        }
        public static explicit operator double(Rational f)
        {
            return f.ToDouble(null);
        }
        public static explicit operator decimal(Rational f)
        {
            return f.ToDecimal(null);
        }
        public TypeCode GetTypeCode()
        {
            return TypeCode.Object;
        }
        public bool ToBoolean(IFormatProvider provider)
        {
            return Numerator != 0;
        }
        public char ToChar(IFormatProvider provider)
        {
            return Convert.ToChar(GetDoubleValue(), provider);
        }
        public sbyte ToSByte(IFormatProvider provider)
        {
            return Convert.ToSByte(GetDoubleValue(), provider);
        }
        public byte ToByte(IFormatProvider provider)
        {
            return Convert.ToByte(GetDoubleValue(), provider);
        }
        public short ToInt16(IFormatProvider provider)
        {
            return Convert.ToInt16(GetDoubleValue(), provider);
        }
        public ushort ToUInt16(IFormatProvider provider)
        {
            return Convert.ToUInt16(GetDoubleValue(), provider);
        }
        public int ToInt32(IFormatProvider provider)
        {
            return Convert.ToInt32(GetDoubleValue(), provider);
        }
        public uint ToUInt32(IFormatProvider provider)
        {
            return Convert.ToUInt32(GetDoubleValue(), provider);
        }
        public long ToInt64(IFormatProvider provider)
        {
            return Convert.ToInt64(GetDoubleValue(), provider);
        }
        public ulong ToUInt64(IFormatProvider provider)
        {
            return Convert.ToUInt64(GetDoubleValue(), provider);
        }
        public float ToSingle(IFormatProvider provider)
        {
            return Convert.ToSingle(GetDoubleValue(), provider);
        }
        public double ToDouble(IFormatProvider provider)
        {
            return GetDoubleValue();
        }
        public decimal ToDecimal(IFormatProvider provider)
        {
            return Convert.ToDecimal(GetDoubleValue(), provider);
        }
        public DateTime ToDateTime(IFormatProvider provider)
        {
            return Convert.ToDateTime(GetDoubleValue(), provider);
        }
        public string ToString(IFormatProvider provider)
        {
            return ToString("F", provider);
        }
        public object ToType(Type conversionType, IFormatProvider provider)
        {
            return Convert.ChangeType(GetDoubleValue(), conversionType);
        }

    }
}

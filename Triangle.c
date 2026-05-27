// Program to validate and Print a triangle using constructors.
// TriTea@blackpharaoh

#include <stdio.h>
#define Max 100

struct Triangle
{
    double sa;
    double sb;
    double sc;
};

void Validate(struct Triangle t)
{
    printf("Sides: %1.f, %1.f, %1.f  Results: ", t.sa, t.sb, t.sc);
    if ((t.sa + t.sb > t.sc) && (t.sa + t.sc > t.sb) && (t.sc + t.sb > t.sa))
    {
        if (t.sa == t.sb && t.sa == t.sc)
            printf("Valid -> Equilateral Triangle\n");
        else if (t.sa == t.sb || t.sb == t.sc || t.sa == t.sc)
            printf("Valid -> Isosceles Triangle\n");
        else
            printf("Valid -> Scalene Triangle\n");
    }
    else
    {
        printf("Invalid -> Not a Triangle\n");
    }
}

int main()
{
    int n;
    struct Triangle tri[Max];

    printf("How many triangles do you want to validate?");
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n--Enter the sides of the triangle %d --\n", i + 1);
        printf("Side A:");
        scanf("%lf", &tri[i].sa);
        printf("Side B:");
        scanf("%lf", &tri[i].sb);
        printf("Side C:");
        scanf("%lf", &tri[i].sc);
    }

    printf("\n--Validate Result--\n");
    for (int i = 0; i < n; i++)
    {
        Validate(tri[i]);
    }
    return 0;
}
// Program to design the academic merit list using the Structures.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>
#define Max 100

struct Stud{
    char name[50];
    char grade;
    double ph;
    double ch;
    double mh;
    double ttl;
    double prt;
};

void calculate(struct Stud *s)
{
    s->ttl = s->ph + s->ch+s->mh;
    s->prt = s->ttl/3.0;

    if(s->prt >= 90.0) 
       s->grade = 'A';
    else if(s->prt >= 75.0)
       s->grade = 'B';
    else if(s->prt >= 50.0)
       s->grade = 'C';
    else
      s->grade = 'F';
}

int main()
{
    int n;
    struct Stud std[Max];
    struct Stud temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i=0; i<n;i++)
    {
        printf("\n--Enter details of student %d --\n", i+1);
        printf("Name: ");
        scanf("%s", std[i].name);
        printf("Physics Marks: ");
        scanf("%lf", &std[i].ph);
        printf("Chemistry Marks: ");
        scanf("%lf", &std[i].ch);
        printf("Mathematics Marks: ");
        scanf("%lf", &std[i].mh);

        calculate(&std[i]);
    }
    //Sorting via bubble sort.
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(std[j].prt<std[j+1].prt)
            {
                temp = std[j];
                std[j] = std[j+1];
                std[j+1] = temp;
            }
        }
    }

    printf("\n--Merit List---\n");
    for(int i=0;i<n;i++)
    {
        printf("Rank %d: %s  Total: %.1f  Percentage: %.2f%%  Grade: %c\n", i+1, std[i].name, std[i].ttl, std[i].prt, std[i].grade);

    }
    return 0;
}
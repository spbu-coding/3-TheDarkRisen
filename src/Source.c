#include <stdio.h>
#include <math.h>

#define Epsilon_f 0.000001f


struct for_float
{
    double x1;
    double x2;
};

struct for_float solve_float(float delta)
{
    struct for_float answer_f;
    answer_f.x2 = (2.0001f + delta - 2) * pow(10, 4);
    answer_f.x1 = 2.0000f - answer_f.x2;

    return answer_f;
}

struct for_double
{
    float x1;
    float x2;
};

struct for_double solve_double(double delta)
{
    struct for_double answer_d;
    answer_d.x2 = (2.0001 + delta - 2) * pow(10, 4);
    answer_d.x1 = 2.0000 - answer_d.x2;

    return answer_d;
}

float distance_f(struct for_float p1, struct for_float p2)
{
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}

double distance_d(struct for_double p1, struct for_double p2)
{
    return sqrtf((p1.x1 - p2.x1) * (p1.x1 - p2.x1) + (p1.x2 - p2.x2) * (p1.x2 - p2.x2));
}
void print() {
    float float_delta = 0.0000f;
    double double_delta = 0.0000;
    float distance_float_points;
    double distance_double_points;
    int step = 1;
    printf("Float_delta = %.20f", float_delta);
    printf("\n Double_delta= %.20lf", double_delta);

    struct for_double double_points = solve_double(double_delta);
    struct for_float float_points = solve_float(float_delta);

    printf("\n double_point: x1 = %.20lf x2 = %.20lf", double_points.x1, double_points.x2);
    printf("\n float_point: x1 = %.20f x2 = %.20f", float_points.x1, float_points.x2);
    float_delta = 0.0001f;
    double_delta = 0.0001;
    do
    {
        printf("\n\n Experiment [%d]", step);
        struct for_double new_double_points = solve_double(double_delta);
        struct for_float new_float_points = solve_float(float_delta);

        distance_float_points = distance_f(float_points, new_float_points);
        distance_double_points = distance_d(double_points, new_double_points);
        

        printf("\n |Delta for double = %.20lf", double_delta);
        printf("\n |New double points:x1 = %.20lf \n |                  x2 = %.20lf", new_double_points.x1, new_double_points.x2);
        printf("\n |Distance between double points = %.20lf", distance_d);

        printf("\n |Delta for floats = %.20f", float_delta);
        printf("\n |New float points: x1 = %.20f \n |                x2 = %.20f", new_float_points.x1, new_float_points.x2);
        printf("\n |Distance between float points = %.20f", distance_f);

        double_delta /= 2.000;
        float_delta /= 2.000f;
        ++step;
    } while ((distance_double_points != 0) || (distance_float_points > Epsilon_f));
}

int main(void) {
    print();
}

/* Generated test code to dump a table of data for external validation
* of the noise model parameters.
*/
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 50; sens <= 3200; sens += 100) {
            double o = compute_noise_model_entry_O(plane, sens);
            double s = compute_noise_model_entry_S(plane, sens);
            printf("%d,%d,%lf,%lf\n", plane, sens, o, s);
        }
    }
    return 0;
}

/* Generated functions to map a given sensitivity to the O and S noise
* model parameters in the DNG noise model. The planes are in
* R, Gr, Gb, B order.
*/
double compute_noise_model_entry_S(int plane, int sens) {
    static double noise_model_A[] = { 6.37406405759e-07,6.21833015267e-07,6.21833015267e-07,5.58101740267e-07 };
    static double noise_model_B[] = { 3.84762176647e-06,9.39145582079e-06,9.39145582079e-06,3.22416542715e-06 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 2.18596637035e-12,2.20885175155e-12,2.20885175155e-12,1.91969405146e-12 };
    static double noise_model_D[] = { 2.84965474945e-07,2.07655218192e-07,2.07655218192e-07,2.63715474423e-07 };
    double digital_gain = (sens / 6375.0) < 1.0 ? 1.0 : (sens / 6375.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 100; sens <= 6375; sens += 100) {
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
    static double noise_model_A[] = { 4.728321776154798e-07,4.4173086265339076e-07,4.4289203689596873e-07,4.720598383085012e-07 };
    static double noise_model_B[] = { 3.5806967113401683e-06,4.4666535915969285e-06,3.5194957974060128e-06,3.2190201375145498e-06 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 3.563631365978534e-13,4.795369237467354e-13,5.002523325052174e-13,3.9926213114537e-13 };
    static double noise_model_D[] = { 5.710656946643617e-07,5.708701653525763e-07,5.971627797288522e-07,5.859050440295477e-07 };
    double digital_gain = (sens / 6375.0) < 1.0 ? 1.0 : (sens / 6375.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

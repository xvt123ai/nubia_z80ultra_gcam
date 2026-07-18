/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 100; sens <= 1594; sens += 100) {
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
    static double noise_model_A[] = { 6.880282875011355e-07,4.323577464100501e-07,4.513240641559701e-07,6.286133461721727e-07 };
    static double noise_model_B[] = { 1.872952371160773e-05,2.2976549580708882e-05,2.409609735713919e-05,2.7741037167203713e-05 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 2.964279802251512e-12,6.648758522638087e-12,5.74028256433148e-12,2.4217616911956404e-12 };
    static double noise_model_D[] = { 3.8903675956452605e-08,-4.125345964226711e-08,-9.72603156719446e-08,-8.41849235082384e-08 };
    double digital_gain = (sens / 1593.0) < 1.0 ? 1.0 : (sens / 1593.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

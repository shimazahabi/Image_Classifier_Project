#define IMAGE_SIZE 28
#define FEATURES_NUMBER 32
#define TRAINED_IMAGES_NUMBER 5000

struct FEATURES_LABELS
{
    float matrix_features[TRAINED_IMAGES_NUMBER][FEATURES_NUMBER];
    int label[TRAINED_IMAGES_NUMBER];
};

// This function handles all of the menu options.
void menu();

// This fucntion clears the screen when a menu opens.
void clear();

// This function is for the start menu.
int start_menu();

// This function is for the main menu.
int main_menu();

// This function prints the information.
void info();

// This function is for the test functions menu for mathematical operations.
int test_functions_menu();

// This function tests the distance arrays function.
void test_distance_arrays();

// This function tests the distance matrix / array function.
void test_distance_mat_arr();

// This function tests the mean of a matrix function.
void test_mean_std();

// This function prints the chosen image from the dataset(trainset).
void print_image(float image[IMAGE_SIZE][IMAGE_SIZE]);

// This function is for the explore dataset menu.(User enters an address and the image will be printed)
void explore_dataset_menu();

// This function calculates the mean of a matrix.
float matrix_mean(float matrix[IMAGE_SIZE][IMAGE_SIZE], int start_x, int end_x, int start_y, int end_y);

// This function calculates the std of a matrix.
float matrix_std(float matrix[IMAGE_SIZE][IMAGE_SIZE], int start_x, int end_x, int start_y, int end_y, float mean);

// This function extractes the features (mean and std) of a matrix[28][28] by dividing it into 16 matrix[7][7] and saves the calculated data in an array[32].
void feature_extraction(float features[], float matrix[IMAGE_SIZE][IMAGE_SIZE]);

// This funtion extractes the features of 5000 random images and saves the calculated data in a matrix[5000][32] and also saves the labels of the images in an array[5000].
void training(FEATURES_LABELS &dataset);

// This function is for the train menu.(Training dataset and printing the accuracy of the algorithm)
void train_menu(FEATURES_LABELS &dataset);

// This function calculates the distance between two arrays.
float distance_arrays(float array1[], float array2[], int num);

// This function calculates the distance between an array[32] and every row of a matrix[5000][32] and saves the calculated data in an array[5000].
void distance_mat_arr(float array[], float matrix[][IMAGE_SIZE], float distance[]);

// This function returns the predicted label of an image from the testset.
int testing(FEATURES_LABELS &dataset, float image[IMAGE_SIZE][IMAGE_SIZE], int k, float &nearest_distance);

// This function is for the test menu.(User enters the address of an image from the testset and the K prarmeter.Then the predicted label by the algortithm will be printed)
void test_menu(FEATURES_LABELS &dataset);

// This function calculates the accuracy of the algorithm.
void accuracy_algorithm(FEATURES_LABELS &dataset);
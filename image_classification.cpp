#include "utils\\utils.hpp"
#include "utils\\timer.hpp"
#include "image_classification.cpp.h"

using namespace std;

bool TRAINING_DATASET = false;

enum START_MENU_OPTIONS
{
    MAIN_MENU = 1,
    INFO = 2,
    TEST_FUNCTIONS_MENU = 3,
    EXIT = 4
};

void clear()
{
    #ifdef _WIN32
    system("cls"); 
    #else
    sysetm("clear");
    #endif

}

void menu() 
{   
    int command;
    
    do{
        clear();
        
        command = start_menu();
        

        clear();

        cout << "Your command is >> "
             << command
             << endl;

        switch (command)
        {
        case MAIN_MENU:
            main_menu();
            break;
        case INFO:
            info();
            break;
        case TEST_FUNCTIONS_MENU:
            test_functions_menu();
            break;
        case EXIT:
            break;
        default:
            cout << "Invalid command";
            break;
        }

        cin.get();
        cin.get();

        
    }
    while(command != 4);

}

int start_menu() 
{

    cout << "      |<< Image Classifier >>|      "
         << endl
         << "1- Main Menu"
         << endl
         << "2- Info"
         << endl
         << "3- Test Functions Menu"
         << endl
         << "4- Exit"
         << endl
         << "Please enter your command..."
         << endl;

    int command;
    cin >> command;

    while(cin.fail()){
        
        cin.clear();
        cin.ignore();

        std::cout << endl
                  << "** ATTENTION : You can only enter numbers...Please try again! :) **"
                  << endl;

        cin.get();
        cin.get();

        cin >> command;
    }

    if(command == 1){
        command = MAIN_MENU;
    } else if(command == 2){
        command = INFO;
    } else if(command == 3){
        command = TEST_FUNCTIONS_MENU;
    } else if(command == 4){
        command = EXIT;
    }

    return command;
}

enum MAIN_MENU_OPTIONS
{
    EXPLORE = 1,
    TRAIN = 2,
    TEST = 3,
    RETURN = 4
};

int main_menu() 
{
    FEATURES_LABELS dataset;

    int command;

    do{

        clear();

        cout << "      |<< Main Menu >>|      "
             << endl
             << "1- Explore images from dataset"
             << endl
             << "2- Train"
             << endl
             << "3- Test"
             << endl
             << "4- Return"
             << endl
             << "Please enter your command..."
             << endl;

        cin >> command;

        while(cin.fail()){

            cin.clear();
            cin.ignore();

            std::cout << endl
                      <<  "** ATTENTION : You can only enter numbers...Please try again! :) **"
                      << endl;

            cin.get();
            cin.get();

            cin >> command;
        }

        if(command == 1){
            command = EXPLORE;
        } else if(command == 2){
            command = TRAIN;
        } else if(command == 3){
            command = TEST;
        } else if(command == 4){
            command = RETURN;
        }

        clear();

        cout << "Your command is >> "
             << command
             << endl;

        switch (command)
        {
        case EXPLORE:
            explore_dataset_menu();
            break;
        case TRAIN:
            train_menu(dataset);
            break;
        case TEST:
            test_menu(dataset);
            break;
        case RETURN:
            break;
        default:
            cout << "Invalid command";
            break;
        } 

        if(command!=4){
        cin.get();
        cin.get();
        }
    }
    while(command != 4);

    return command;

}

void info()
{
    cout << "      |<< Info >>|      "
         << endl
         << "|| This application can do the following tasks:"
         << endl
         << "+ Classify an input image (The input image belongs to the mnist dataset)"
         << endl
         << "+ Setting parameters of the algorithm -The K parameter."
         << endl
         << "+ Extract features from the input image as well as the training sets."
         << endl
         << "+ Save the extracted features from training sets to a file."
         << endl
         << "+ Read the extracted features from a file."
         << endl
         << endl
         << "# Programmer : Shima Zahabi :)"
         << endl
         << "# Email : shimazahabi83@gmail.com"
         << endl;
}

enum TEST_FUNCTIONS_MENU_OPTIONS
{
    DISTANCE_ARRAYS = 1,
    DISTANCE_ARRAY_MATRIX = 2,
    MEAN_STD = 3,
    RETURN_MENU = 4
};

int test_functions_menu()
{
    int command;

    do{

        clear();

        cout << "      |<< Test Functions Menu >>|      "
             << endl
             << "1- Distance arrays"
             << endl
             << "2- Distance array and matrix"
             << endl
             << "3- Mean and Std of a matrix"
             << endl
             << "4- Return"
             << endl
             << "Please enter your command..."
             << endl;

        cin >> command;

        while(cin.fail()){

            cin.clear();
            cin.ignore();

            std::cout << endl
                      <<  "** ATTENTION : You can only enter numbers...Please try again! :) **"
                      << endl;

            cin.get();
            cin.get();

            cin >> command;
        }

        if(command == 1){
            command = DISTANCE_ARRAYS;
        } else if(command == 2){
            command = DISTANCE_ARRAY_MATRIX;
        } else if(command == 3){
            command = MEAN_STD;
        } else if(command == 4){
            command = RETURN_MENU;
        }

        clear();

        cout << "Your command is >> "
             << command
             << endl;

        switch (command)
        {
        case DISTANCE_ARRAYS:
            test_distance_arrays();
            break;
        case DISTANCE_ARRAY_MATRIX:
            test_distance_mat_arr();
            break;
        case MEAN_STD:
            test_mean_std();
            break;
        case RETURN_MENU:
            break;
        default:
            cout << "Invalid command";
            break;
        } 

        if(command != 4){
        cin.get();
        cin.get();
        }
    }
    while(command != 4);

    return command;
}

void test_distance_arrays()
{
    cout << "      |<< Test Distance Arrays Function >>|      "
         << endl;

    float array1[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float array2[32] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    float distance = distance_arrays(array1, array2, 32);

    cout << endl
         << "array1[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}"
         << endl 
         << "array2[32] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}"
         << endl 
         << endl
         << "# Calculated distance is: "
         << distance
         << endl
         << "|| If distance is equal to 5.65685, the function is working correctly :)"
         << endl;
}

void test_distance_mat_arr()
{   
    cout << "      |<< Test Distance Array / Matrix Function >>|      "
         << endl;

    float array[5]={2, 2, 2, 2, 2};
    float matrix[5][5]={{1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1}};
    float distance[5];

    for(int i = 0; i < 5; i++){

        distance[i] = distance_arrays(array, matrix[i], 5);
    }
    cout << endl
         << "array[5] = {2, 2, 2, 2, 2} \n"
         << "matrix[5][5] = {{1, 1, 1, 1, 1}, \n"
         << "               {1, 1, 1, 1, 1}, \n"
         << "               {1, 1, 1, 1, 1}, \n"
         << "               {1, 1, 1, 1, 1}, \n"
         << "               {1, 1, 1, 1, 1}} \n"
         << endl
         << "# Calculated distance is ";

    for(int i=0; i<5; i++){
        std::cout << distance[i] << ", ";
    }

    cout << endl
         << "|| If distance[5] is equal to {2.23607, 2.23607, 2.23607, 2.23607, 2.23607}, the function is working correctly :)"
         << endl;
}

void test_mean_std()
{   
    cout << "      |<< Test Mean / Std Function >>|      "
         << endl;

    string image_path = interpolation("data\\mnist", "train", "7");
    float img[IMAGE_SIZE][IMAGE_SIZE];

    load_image(image_path, 200, img);

    cout << endl
         << "200th image from the label 7"
         << endl;

    float mean = matrix_mean(img, 7, 14, 0, 7); 

    cout << endl
         << "# Calculated mean is: "
         << mean 
         << endl
         << "|| If mean is equal to 0.714286, the function is working correctly :)"
         << endl;

    float std = matrix_std(img, 7, 14, 0, 7, mean); 
    cout << "# Calculated std is: "
         << std
         << endl
         << "|| If std is equal to  4.21307, the function is working correctly :)"
         << endl;
}

void print_image(float image[IMAGE_SIZE][IMAGE_SIZE])
{
    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 28; j++)
        {   
            if(image[i][j] == 0){
                cout << " ";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void explore_dataset_menu()
{
    cout << "      |<< Explore Images From Dataset >>|      "
         << endl
         <<  "Please enter the label (0 to 9)..."
         << endl;
    
    string label;

    cin >> label;

    while((label.length() != 1) || !(label[0] >= '0' && label[0] <= '9')){

        cout << "** Wrong Command (This label is not available)...Please try again...! :) **"
             << endl;

        cin >> label;
    }

    string image_path = interpolation("data\\mnist", "train", label);

    cout << endl
         << "Please enter the number of the image..."
         << endl;

    int number;

    cin >> number;

    while( ! (number >= 1 && number <= file_count(image_path)) ){

        cout << "** Wrong Command (This number is not available)...Please try again...! :) **"
             << endl;

        cin >> number;       
    }

    while(cin.fail()){

        cin.clear();
        cin.ignore();

        std::cout << endl
                  <<  "** ATTENTION : You can only enter numbers...Please try again! :) **"
                  << endl;

        cin.get();
        cin.get();

        cin >> number;
    }

    cout << endl;
    
    float img[IMAGE_SIZE][IMAGE_SIZE];

    load_image(image_path, number, img);

    print_image(img);

    cout << "# LABEL OF THE IMAGE : "
         << label
         << endl
         << "# NUMBER OF THE IMAGE : "
         << number
         << endl;
}

float matrix_mean(float matrix[IMAGE_SIZE][IMAGE_SIZE], int start_x, int end_x, int start_y, int end_y)
{   
    float sum = 0;
    float mean;

    for(int i = start_x; i < end_x; i++){

        for(int j = start_y; j < end_y; j++){

            sum += matrix[i][j];
        }
    }

    mean = sum / 49;

    return mean;
}

float matrix_std(float matrix[IMAGE_SIZE][IMAGE_SIZE], int start_x, int end_x, int start_y, int end_y, float mean)
{
    float sum = 0;
    float std;

    for(int i = start_x; i < end_x; i++){

        for(int j = start_y; j < end_y; j++){

            sum += pow ( ( matrix[i][j] - mean ) , 2 );
        }
    }
    
    std = sqrt ( sum / 48 );

    return std;
}

void feature_extraction(float features[], float matrix[IMAGE_SIZE][IMAGE_SIZE])
{   
    int k = 0;
    for(int i = 0; i < IMAGE_SIZE; i += 7){

        for(int j = 0; j < IMAGE_SIZE; j += 7){

            int start_x = i;
            int end_x = i + 7;
            int start_y = j;
            int end_y = j + 7;

            float mean = matrix_mean(matrix, start_x, end_x, start_y, end_y);
            float std = matrix_std(matrix, start_x, end_x, start_y, end_y, mean);

        
            features[k] = mean;
            features[k+1] = std;
            k += 2;
        }
    }
}

void training(FEATURES_LABELS &dataset)
{
    int index = 0;

    string label;

    srand(time(NULL));

    for(int i = 0; i < 10; i++){

        label = '0' + i;

        string image_path = interpolation("data\\mnist", "train", label);

        for(int j = 0; j < 500; j++){

        float img[IMAGE_SIZE][IMAGE_SIZE];

        int number = (rand() % file_count(image_path)) + 1;

        load_image(image_path, number, img);

        feature_extraction(dataset.matrix_features[index], img);

        dataset.label[index] = i;

        index += 1;
        }
    }   
}

void train_menu(FEATURES_LABELS &dataset)
{   
    TRAINING_DATASET = true;

    cout << "      |<< Train Menu >>|      "
         << endl
         << "Extracting features of 5000 images...! :)"
         << endl
         << "Calculating the accuracy of the algorithm...PLEASE WAIT...! :) "
         << endl;

    training(dataset);

    accuracy_algorithm(dataset);
}

float distance_arrays(float array1[], float array2[], int num)
{   
    float sum = 0;

    for(int i = 0; i < num; i++){

        sum += pow ( ( array1[i] - array2[i] ) , 2 );
    }

    float distance;

    distance = sqrt(sum);

    return distance;
}

void distance_mat_arr(float array[], float matrix[][FEATURES_NUMBER], float distance[])
{
    for(int i = 0; i < TRAINED_IMAGES_NUMBER; i++){

        distance[i] = distance_arrays(array, matrix[i], FEATURES_NUMBER);
    }
}

int testing(FEATURES_LABELS &dataset, float image[IMAGE_SIZE][IMAGE_SIZE], int k, float &nearest_distance)
{
    float test_image_features[FEATURES_NUMBER];
    feature_extraction(test_image_features, image);

    float distance[TRAINED_IMAGES_NUMBER];

    distance_mat_arr(test_image_features, dataset.matrix_features, distance);

    float minimum = 1000;

    vector<int> k_minimums_labels;
    vector<float> k_minimums;

    for(int i = 0; i < TRAINED_IMAGES_NUMBER; i++){

        if(distance[i] <= minimum && k_minimums.size() < k){

            minimum = distance[i];

            k_minimums.push_back(minimum);

            k_minimums_labels.push_back(dataset.label[i]);

        } else if(distance[i] <= minimum && k_minimums.size() == k){

            minimum = distance[i];

            k_minimums.erase(k_minimums.begin());

            k_minimums.push_back(minimum);

            k_minimums_labels.erase(k_minimums_labels.begin());

            k_minimums_labels.push_back(dataset.label[i]);
        }
    }

    int max_repeated = 0;
    int MAX_REPEATED_LABEL;

    for(int i = 0; i < k_minimums_labels.size(); i++){

        int count = 0;

        for(int j = 0; j < k_minimums_labels.size(); j++){

            
            if(k_minimums_labels[i] == k_minimums_labels[j]){

                count++;
            }

            if(count >= max_repeated){

                max_repeated = count;

                MAX_REPEATED_LABEL = k_minimums_labels[i];
            }
        }
    }
    nearest_distance = k_minimums.back();

    return MAX_REPEATED_LABEL; 
}

void test_menu(FEATURES_LABELS &dataset)
{   
    cout << "      |<< Test Menu >>|      "
         << endl
         << "Please choose the address of the image..."
         << endl
         << "Please enter the label: ";

    string label;

    cin >> label;

    while((label.length() != 1) || !(label[0] >= '0' && label[0] <= '9')){

        cout << "** Wrong Command (This label is not available)...Please try again...! :) **"
             << endl;

        cin >> label;
    }

    string image_path = interpolation("data\\mnist", "test", label);

    cout << endl
         << "Please enter the number of the image: "
         << endl;

    int number;

    cin >> number;

    while( ! (number >= 1 && number <= file_count(image_path)) ){

        cout << "** Wrong Command (This number is not available)...Please try again...! :) **"
             << endl;

        cin >> number;       
    }

    while(cin.fail()){

        cin.clear();
        cin.ignore();

        std::cout << endl
                  <<  "** ATTENTION : You can only enter numbers...Please try again! :) **"
                  << endl;

        cin.get();
        cin.get();

        cin >> number;
    }

    
    cout << endl
         << "Please enter the parameter K: "
         << endl;

    int k;
    cin >> k;

    while(cin.fail()){

        cin.clear();
        cin.ignore();

        std::cout << endl
                  <<  "** ATTENTION : You can only enter numbers...Please try again! :) **"
                  << endl;

        cin.get();
        cin.get();

        cin >> k;
    }

    if(TRAINING_DATASET == false){
        training(dataset);
    }
 
    float img[IMAGE_SIZE][IMAGE_SIZE];
    load_image(image_path, number, img);

    print_image(img);

    float nearest_distance;

    string PREDICTED_LABEL;
    PREDICTED_LABEL = '0' + testing(dataset, img, k, nearest_distance);

    cout << "|| According to this image classification algorithm, the input image is classified into the:(The predicted label) "
         << endl
         << "|| ## LABEL "
         << PREDICTED_LABEL
         << " (The real label is "
         << label 
         << ")"
         << endl
         << "|| The distance with the nearest image is: "
         << endl
         << "|| ## DISTANCE " 
         << nearest_distance
         << endl
         << "|| The algorithm is working with the chosen K parameter: "
         << endl
         << "|| ## THE K PARAMETER "
         << k
         << endl;
}

void accuracy_algorithm(FEATURES_LABELS &dataset)
{
    float count = 0;

    for(int i = 0; i < 10; i++){

        string label;
        label = '0' + i;

        string image_path = interpolation("data\\mnist", "test", label);

        float img[IMAGE_SIZE][IMAGE_SIZE];

        for(int j = 1; j < file_count(image_path); j++){
            
            load_image(image_path, j, img);

            float nearest_distance;

            int real_value = i; 

            int predicted_value = testing(dataset, img, 1, nearest_distance); 

            if(real_value == predicted_value){
                count++;
            }
        }
    }
    
    float accuracy;
    accuracy = (count / 10000) * 100;

    cout << endl
         << "|| Accuracy of the algorithm is: "
         << accuracy
         << "% ||"
         << endl;
} 


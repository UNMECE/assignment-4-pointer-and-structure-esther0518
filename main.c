#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

int main(int argc, char *argv[]){
    //Allocate the memory for the 5 items
    Item *item_list = (Item*)malloc(5* sizeof(Item));
    //takes the second argument of argv to look for it later
    char *search_sku = argv[1];

    //add items to the list
    add_item(item_list, 3.32, "12345", "Dariy", "Milk", 0);
    add_item(item_list, 4.44, "23456", "Breakfast and Cereal", "Cinnamon Toast Crunch", 1);
    add_item(item_list, 3.42, "34567", "Bread and Bakery", "Bread", 2);
    add_item(item_list, 7.74, "45678", "Beverages", "Coca-Cola", 3);
    add_item(item_list, 39.95, "56789", "Toys", "Lego set", 4);

    //print the items
    print_items(item_list, 5);

    //find the avergae price and print it
    double avg = average_price(item_list, 5);
    printf("Average price is: %.2f\n\n", avg);

    //take second main line argument as sku search and print item if found
    int i = 0;
    int size = 5;
    //loop will continue until the sku number is found
    while(i<size && strcmp(item_list[i].sku, search_sku) != 0){
        i++;
    }

    //checks to see if the item was found or if it went through the whole list without finding anything
    if(i<size){
        printf("Item found:\n");
        print_items(&item_list[i], 1);
    }else{
        printf("Item not found.\n");
    }

    //free the allocated memory
    free_items(item_list,5);
    return 0;
}

//allocates memory for item information
void add_item(Item *item_list, double price, const char *sku, const char *category, const char *name, int index){
    item_list[index].price = price;

    //allocate memory and copy the content
    item_list[index].sku = (char*)malloc(sizeof(sku));
    strcpy(item_list[index].sku, sku);

    item_list[index].name = (char*)malloc(sizeof(name));
    strcpy(item_list[index].name, name);

    item_list[index].category = (char*)malloc(sizeof(category));
    strcpy(item_list[index].category, category);

}

//free the allocated memory
void free_items(Item *item_list, int size){
    for(int i=0; i<size; i++){
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }

    free(item_list);
}

//finds the average of the items
double average_price(Item *item_list, int size){
    double total = 0;
    for(int i=0; i<size; i++){
        total += item_list[i].price;
    }

    return total/size;
}

//pritns the items information
void print_items(Item *item_list, int size){
    for(int i=0; i<size; i++){
        printf("**********\n");
        printf("Item name: %s\n", item_list[i].name);
        printf("Item SKU: %s\n", item_list[i].sku);
        printf("Item category: %s\n", item_list[i].category);
        printf("Item price: %.2f\n", item_list[i].price);
        printf("**********\n");

    }
}
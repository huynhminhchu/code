#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 25


struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(const struct part *inventory, int num_parts, int number);
void insert(struct part *inventory, int *num_parts);
void search(struct part *inventory, int num_parts);
void update(struct part *inventory, int num_parts);
void print(struct part *inventory, int num_parts);
void organize_inventory(struct part *inventory, int num_parts);
#endif

// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage;
        first->prev = nullptr;
        first->next = nullptr;
        first->light = true;
    }
    else if (first != nullptr) {
        Cage* cage = new Cage;
        cage->next = nullptr;
        cage->prev = nullptr;
        cage->light = light;
        Cage* tmp;
        if (first->next == nullptr) {
            cage->next = first;
            cage->prev = first;
            first->next = cage;
            first->prev = cage;
        } else {
            tmp = first;
            while (tmp->next != first) {
                tmp = tmp->next;
            }
            tmp->next = cage;
            cage->next = first;
            cage->prev = tmp;
            first->prev = cage;
        }
    }
}

int Train::getLength() {
    Cage* tmp = first;
    int count = 0;
    while (tmp) {
        tmp = tmp->next;
        countOp++;
        count++;
        if (tmp->light == 1) {
            tmp->light = 0;
            for (int i = 0; i < count; i++) {
                tmp = tmp->prev;
                countOp++;
            }
        if (tmp->light == 0) {
            return count;
            count = 0;
        }
        }
    }
    return 0;
}

int Train::getOpCount() {
      if (countOp == 0)
          getLength();
    return countOp;
}

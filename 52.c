#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define SUITS 4
#define RANKS 13

typedef struct {
    const char *rank;
    const char *suit;
} Card;

void build_deck(Card *deck) {
    const char *ranks[RANKS] = {
        "Ace", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "Jack", "Queen", "King"
    };
    const char *suits[SUITS] = {
        "Hearts", "Diamonds", "Clubs", "Spades"
    };
    int index = 0;
    for (int s = 0; s < SUITS; s++) {
        for (int r = 0; r < RANKS; r++) {
            deck[index].rank = ranks[r];
            deck[index].suit = suits[s];
            index++;
        }
    }
}

void shuffle_deck(Card *deck) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main(void) {
    Card deck[DECK_SIZE];
    srand((unsigned int)time(NULL));
    build_deck(deck);
    shuffle_deck(deck);
    printf("Dealt 5 cards from 52-card deck:\n");
    for (int i = 0; i < 5; i++) {
        printf("  %s of %s\n", deck[i].rank, deck[i].suit);
    }
    printf("Total cards in deck: %d\n", DECK_SIZE);
    return 0;
}


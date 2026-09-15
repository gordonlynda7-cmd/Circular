#ifndef Circular_List
#define Circular_List

template <typename T>
struct Card
{
    T value;
    Card<T> *nextCard;
};

template <typename T>
class CircularLinkedList
{
private:
    Card<T> *firstCard;

public:
    CircularLinkedList()
    {
        firstCard = nullptr;
    }

    void addToRing(const T &newValue)
    {
        Card<T> *newCard = new Card<T>(newValue);

        if (firstCard == nullptr)
        {
            // CASE 1: the ring is empty right now
            firstCard = newCard;
            newCard->nextCard = firstCard;
        }
        else
        {
            // CASE 2: the ring already has at least one card in it
            Card<T> *currentCard = firstCard;
            while (currentCard->nextCard != firstCard)
            {
                currentCard = currentCard->nextCard;
            }
            currentCard->nextCard = newCard;
            newCard->nextCard = firstCard;
        }
    }
};

#endif
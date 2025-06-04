#include "getContinents.cpp"

void GameField::activeShahtsControl() {
    this->activeShahts.forEach([](ProtoObj* shaht){
        shaht->activeProg();
    });
    this->activeShahts.filterSelf([](ProtoObj* shaht){
        if (!shaht->clients.length && !shaht->potentialClients.length) {
            shaht->isActive = false;
            return true;
        }
        return false;
    });
}
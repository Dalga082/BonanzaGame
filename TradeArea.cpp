#include "TradeArea.h" 

TradeArea::TradeArea(istream& in, const CardFactory* set) {

}

TradeArea& TradeArea::operator+=(Card* card) {
	trade_area.push_back(card);
	return *this;
}

bool TradeArea::legal(Card* card) {
	for (Card* c : trade_area) {
		if (card->getName() == c->getName()) {
			return true;
		}
	}
	return false;
}

Card* TradeArea::trade(string name) {
	for (CardList::iterator iter = trade_area.begin(); iter != trade_area.end(); iter++) {
		if ((*iter)->getName() == name) {
			return *trade_area.erase(iter);
		}
	}
}

int TradeArea::numCards() {
	return trade_area.size();
}
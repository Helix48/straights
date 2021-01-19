#include "StraightsEngine.h"
#include "TextView.h"
#include "Keyboard.h"

StraightsEngine::StraightsEngine(int seed)
    : Clubs{{}},
      Diamonds{{}},
      Hearts{{}},
      Spades{{}},
      seed{seed},
      scores{0,0,0,0} {
    addView(std::make_unique<TextView>(*this));
    addController(std::make_unique<Keyboard>());
    deck.shuffleDeck(seed);
    currPlayer = deck.startPlayer();
}

void StraightsEngine::getPlayers(){
    updateViews(1,"IsHuman");
    players.push_back(Player{deck.createHand(0,12),getIsHuman(),1,0});
    updateViews(2,"IsHuman");
    players.push_back(Player{deck.createHand(13,25),getIsHuman(),2,0});
    updateViews(3,"IsHuman");
    players.push_back(Player{deck.createHand(26,38),getIsHuman(),3,0});
    updateViews(4,"IsHuman");
    players.push_back(Player{deck.createHand(39,51),getIsHuman(),4,0});
}

void StraightsEngine::start(){
    getPlayers();
    int maxScore = 0;
    while (maxScore < 80){
        updateViews((currPlayer + 1), "Round");
        for(int i = 0; i < 52; i++){
            //std::cout << players[currPlayer].getHand().getSize() << std::endl;
            //players[currPlayer].getHand().print(std::cout, "handd");
            players[currPlayer].calculateLegalPlays(Clubs, Diamonds, Hearts, Spades);
            if (players[currPlayer].getIsHuman()){
                updateViews(Clubs, Hearts, Diamonds, Spades, players[currPlayer].getHand(), players[currPlayer].getLegalPlays());
                bool legalMove = false;
                while(!legalMove) {
                    std::string move = getMove();
                    if(move == "play"){
                        Card card = getCard();
                        //std::cout<< card.getSuit() << " " << card.getValue() << std::endl;
                        if (players[currPlayer].getLegalPlays().isCard(card)){
                            players[currPlayer].play(card, Clubs, Diamonds, Hearts, Spades);
                            //std::cout<<Clubs.getSize()<<Diamonds.getSize()<<Hearts.getSize()<<Spades.getSize()<<std::endl;
                            updateViews((currPlayer + 1), card, "plays");
                            legalMove = true;
                        }
                        else
                            updateViews("play");
                    }
                    else if(move == "discard"){
                        Card card = getCard();
                        if (players[currPlayer].getLegalPlays().getSize() > 0)
                            updateViews("discard");
                        else{
                            players[currPlayer].discard(card);
                            scores[currPlayer] += card.getValue();
                            updateViews((currPlayer + 1), card, "discards");
                            legalMove = true;
                        }
                    }
                    else if(move == "deck"){
                        deck.print(std::cout);
                    }
                    else if(move == "quit"){
                        maxScore = 80;
                        i = 52;
                        break;
                    }
                    else if(move == "ragequit"){
                        updateViews((currPlayer + 1), "Ragequit");
                        players[currPlayer].ragequit();
                        std::string action = "plays";
                        Card card = players[currPlayer].computerMove();
                        if (players[currPlayer].getLegalPlays().getSize() == 0) {
                            action = "discards";
                            scores[currPlayer] += card.getValue();
                            players[currPlayer].discard(card);
                        }
                        else
                            players[currPlayer].play(card, Clubs, Diamonds, Hearts, Spades);
                        updateViews((currPlayer + 1), card, action);
                        legalMove = true;
                    }
                    else {
                        std::cout << "Invalid command: \"" << move << "\"" << std::endl;
                    }
                }
            }
            else{
                //updateViews(Clubs, Hearts, Diamonds, Spades, players[currPlayer].getHand(), players[currPlayer].getLegalPlays());
                std::string action = "plays";
                Card card = players[currPlayer].computerMove();
                if (players[currPlayer].getLegalPlays().getSize() == 0) {
                    action = "discards";
                    scores[currPlayer] += card.getValue();
                    //std::cout <<"b4" << players[currPlayer].getHand().getSize() << std::endl;
                    players[currPlayer].discard(card);
                    //std::cout <<"af"<< players[currPlayer].getHand().getSize() << std::endl;
                }
                else{
                    players[currPlayer].play(card, Clubs, Diamonds, Hearts, Spades);
                }
                //std::cout << players[currPlayer].getHand().getSize() << std::endl;
                updateViews((currPlayer + 1), card, action);
            }
            currPlayer++;
            currPlayer %= 4;
        }
        updateViews(1,players[0].getDiscards());
        updateViews(1,scores[0],players[0].getScore());
        updateViews(2,players[1].getDiscards());
        updateViews(2,scores[1],players[1].getScore());
        updateViews(3,players[2].getDiscards());
        updateViews(3,scores[2],players[2].getScore());
        updateViews(4,players[3].getDiscards());
        updateViews(4,scores[3],players[3].getScore());
        Clubs.emptyHand();
        Diamonds.emptyHand();
        Hearts.emptyHand();
        Spades.emptyHand();
        deck.shuffleDeck(seed);
        std::vector<Player> newPlayers;
        newPlayers.push_back(Player{deck.createHand(0,12),players[0].getIsHuman(),1,players[0].getScore() + scores[0]});
        newPlayers.push_back(Player{deck.createHand(13,25),players[1].getIsHuman(),2,players[1].getScore() + scores[1]});
        newPlayers.push_back(Player{deck.createHand(26,38),players[2].getIsHuman(),3,players[2].getScore() + scores[2]});
        newPlayers.push_back(Player{deck.createHand(39,51),players[3].getIsHuman(),4,players[3].getScore() + scores[3]});
        players.clear();
        players = newPlayers;
        currPlayer = deck.startPlayer();
        for (auto i : players) {
            if (i.getScore() > maxScore) {
                maxScore = i.getScore();
            }
        }
        for (auto &i : scores) {
            i = 0;
        }
    }
    int minScore = maxScore;
    for (auto i : players){
        if (i.getScore() < minScore)
            minScore = i.getScore();
    }
    for (int i = 0; i < 4; i++){
        if (players[i].getScore() == minScore) {
            updateViews(i + 1, "Win");
        }
    }
}

#include "plane.h"
using namespace std;

#ifndef PROJECT_RUNWAY_H
#define PROJECT_RUNWAY_H

class Runway : public WriteToFile {
    private:
        static int idCnt;
        int id{};
        string airportName{};
        int distance{};
    public:
        Runway(string airportName, int distance) : airportName(std::move(airportName)), distance(distance){
            this->id = idCnt++;
        }
        Runway() = default;
        ~Runway() = default;
        static void setIdCnt(int id);
        static int getIdCnt();
        static void printRunway(int);
        [[nodiscard]] int getId() const;
        [[nodiscard]] string getAirportName() const;
        [[nodiscard]] int getDistance() const;
        [[nodiscard]] nlohmann::json toJson() const override;
        friend void from_json(const nlohmann::json&, Runway&);
        friend ostream& operator<<(ostream&, const Runway&);
};

#endif //PROJECT_RUNWAY_H
#pragma once

#include "Core/FileSystem.hpp"
#include "Localisation/FormatArguments.hpp"
#include "Map/Map.hpp"
#include <cstdint>

namespace OpenLoco
{
    enum class MonthId : uint8_t;
}

namespace OpenLoco::Scenario
{
    namespace Flags
    {
        constexpr uint16_t landscapeGenerationDone = (1 << 0);
        constexpr uint16_t hillsEdgeOfMap = (1 << 1);
        constexpr uint16_t preferredOwnerName = (1 << 2);
    }

    namespace ObjectiveFlags
    {
        constexpr uint8_t beTopCompany = (1 << 0);
        constexpr uint8_t beWithinTopThreeCompanies = (1 << 1);
        constexpr uint8_t withinTimeLimit = (1 << 2);
        constexpr uint8_t flag_3 = (1 << 3);
        constexpr uint8_t flag_4 = (1 << 4);
    }

    enum class ObjectiveType : uint8_t
    {
        companyValue,
        vehicleProfit,
        performanceIndex,
        cargoDelivery,
    };

    enum class Season : uint8_t
    {
        autumn = 0,
        winter = 1,
        spring = 2,
        summer = 3,
    };

    // NB: kMinYear has been changed to 1800 in OpenLoco; Locomotion uses 1900.
    constexpr uint16_t kMinYear = 1800;
    constexpr uint16_t kMaxYear = 2100;

    constexpr uint8_t kMinObjectiveYearLimit = 2;
    constexpr uint8_t kMaxObjectiveYearLimit = 100;

    constexpr uint32_t kMinObjectiveCompanyValue = 100000;
    constexpr uint32_t kMaxObjectiveCompanyValue = 200000000;

    constexpr uint32_t kMinObjectiveMonthlyProfitFromVehicles = 1000;
    constexpr uint32_t kMaxObjectiveMonthlyProfitFromVehicles = 1000000;

    constexpr uint32_t kMinObjectivePerformanceIndex = 10;
    constexpr uint32_t kMaxObjectivePerformanceIndex = 100;

    constexpr uint32_t kMinObjectiveDeliveredCargo = 100;
    constexpr uint32_t kMaxObjectiveDeliveredCargo = 200000000;

    constexpr uint8_t kMinCompetingCompanies = 0;
    constexpr uint8_t kMaxCompetingCompanies = 14;

    constexpr uint8_t kMinCompetitorStartDelay = 0;
    constexpr uint8_t kMaxCompetitorStartDelay = 240;

    constexpr uint16_t kMinStartLoanUnits = 50;
    constexpr uint16_t kMaxStartLoanUnits = 1250;

    constexpr uint16_t kMinLoanSizeUnits = 50;
    constexpr uint16_t kMaxLoanSizeUnits = 5000;

    constexpr uint16_t kMinLoanInterestUnits = 5;
    constexpr uint16_t kMaxLoanInterestUnits = 25;

    constexpr uint8_t kMinSeaLevel = 0;
    constexpr uint8_t kMaxSeaLevel = 28;

    constexpr uint8_t kMinBaseLandHeight = 0;
    constexpr uint8_t kMaxBaseLandHeight = 15;

    constexpr uint8_t kMinHillDensity = 0;
    constexpr uint8_t kMaxHillDensity = 100;

    constexpr uint16_t kMinNumForests = 0;
    constexpr uint16_t kMaxNumForests = 990;

    constexpr uint8_t kMinForestRadius = 4;
    constexpr uint8_t kMaxForestRadius = 40;

    constexpr uint8_t kMinForestDensity = 1;
    constexpr uint8_t kMaxForestDensity = 7;

    constexpr uint16_t kMinNumTrees = 0;
    constexpr uint16_t kMaxNumTrees = 20000;

    constexpr uint8_t kMinAltitudeTrees = 0;
    constexpr uint8_t kMaxAltitudeTrees = 40;

    Season nextSeason(Season season);
    void initialiseSnowLine();
    void updateSnowLine(int32_t currentDayOfYear);

    // 0x00525FB4
    Map::SmallZ getCurrentSnowLine();
    void setCurrentSnowLine(Map::SmallZ snowline);

    // 0x00525FB5
    Season getCurrentSeason();
    void setCurrentSeason(Season season);

    void reset();
    void sub_4748D4();
    void eraseLandscape();
    void generateLandscape();
    void initialiseDate(uint16_t year);

    void initialiseDate(uint16_t year, OpenLoco::MonthId month, uint8_t day);

    /**
     * Loads the given scenario file, but does not initialise any game state.
     */
    bool load(const fs::path& path);

    /**
     * Loads the given scenario file and resets the game state for starting a new scenario.
     */
    bool loadAndStart(const fs::path& path);

    /**
     * Resets the game state (e.g. companies, year, money etc.) for starting a new scenario.
     */
    [[noreturn]] void start();

    void registerHooks();
    void formatChallengeArguments(FormatArguments& args);
    void sub_46115C();
}

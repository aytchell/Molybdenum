#ifndef MOLYBDENUM_MAGICBITBOARDS_H
#define MOLYBDENUM_MAGICBITBOARDS_H

#include "BitStuff.h"
#include <cstring>

constexpr std::array<int, 64> bishopShifts =
        {58, 59, 59, 59, 59, 59, 59, 58,
         59, 59, 59, 59, 59, 59, 59, 59,
         59, 59, 57, 57, 57, 57, 59, 59,
         59, 59, 57, 55, 55, 57, 59, 59,
         59, 59, 57, 55, 55, 57, 59, 59,
         59, 59, 57, 57, 57, 57, 59, 59,
         59, 59, 59, 59, 59, 59, 59, 59,
         58, 59, 59, 59, 59, 59, 59, 58};

constexpr std::array<int, 64> rookShifts =
        {52, 53, 53, 53, 53, 53, 53, 52,
         53, 54, 54, 54, 54, 54, 54, 53,
         53, 54, 54, 54, 54, 54, 54, 53,
         53, 54, 54, 54, 54, 54, 54, 53,
         53, 54, 54, 54, 54, 54, 54, 53,
         53, 54, 54, 54, 54, 54, 54, 53,
         53, 54, 54, 54, 54, 54, 54, 53,
         52, 53, 53, 53, 53, 53, 53, 52};

//Magic numbers are hard coded to reduce startup time,
//they were generated by uncommenting the commented code in initMagics
constexpr std::array<u64, 64> bishopMagics {
        5226430236606988800ULL, 5226430236606988800ULL, 308593332580267072ULL, 362825647322173444ULL,
        4804041364242448ULL, 1297319404912069120ULL, 13840126872677277704ULL, 9385783651125955076ULL,
        497546326180096ULL, 9269569220503421568ULL, 603486765363380480ULL, 578716967385432082ULL,
        2341893951620917249ULL, 18050751216550088ULL, 4508019168678144ULL, 5188182646610464832ULL,
        9241405540151896320ULL, 9227981601999814788ULL, 1227512407929136514ULL, 4612811923233210374ULL,
        9305563007090163714ULL, 74318469126033409ULL, 2814756243185666ULL, 4638753796905504768ULL,
        7134938761412478984ULL, 298367890810152968ULL, 1333633938320786432ULL, 580968749981503520ULL,
        759146826082336768ULL, 9335962577899389952ULL, 1153207382468461568ULL, 2594364755991068928ULL,
        149489635276361856ULL, 444176738839572488ULL, 92367582660608ULL, 144117389247119489ULL,
        594475726349598980ULL, 9818005519490941072ULL, 9806614613989592200ULL, 2253999644442756ULL,
        73469779840599044ULL, 291440110338634ULL, 666852781251891200ULL, 1306057386733148161ULL,
        2542083780903936ULL, 72726102920941824ULL, 4638712171014922753ULL, 13523997318722625ULL,
        10664880228777133120ULL, 282579052932096ULL, 9800959790733590561ULL, 9943986186370548480ULL,
        87821344003325960ULL, 4611721220790976512ULL, 38423567738863618ULL, 9033727145443328ULL,
        9297226237383032836ULL, 288793609607651330ULL, 180319954210426880ULL, 72092784858793993ULL,
        9800009950394188296ULL, 5764607696007857664ULL, 289928030830330890ULL, 4505807442154384ULL,
};

constexpr std::array<u64, 64> rookMagics {
        2341873049361449088ULL, 18015016991064128ULL, 648536350844797185ULL, 1224996695127885828ULL,
        9943983307635560460ULL, 4755816599868418053ULL, 288247985535582360ULL, 4755810158298006017ULL,
        1193594782623776768ULL, 141012374872064ULL, 9233083473575583744ULL, 315392951997960192ULL,
        2392554490300418ULL, 563293888577656ULL, 600104685353119748ULL, 140824738267392ULL,
        18014948274749472ULL, 22518273551646720ULL, 9516110960973087376ULL, 4611827305805778944ULL,
        1513350762241984512ULL, 563499751187456ULL, 2484896564119568ULL, 1154401447266287740ULL,
        9962842536949071875ULL, 4613744305268891648ULL, 2306265505148829712ULL, 162692648208973984ULL,
        18652117401600128ULL, 865254361877714960ULL, 74590873123422220ULL, 72066690778694657ULL,
        9259471271882653824ULL, 2387048677442076673ULL, 9799867974654366466ULL, 2305852909666963456ULL,
        4644354303985664ULL, 1154482813274161664ULL, 289919261479013409ULL, 5188149261845405825ULL,
        72198606410514432ULL, 22588371184451632ULL, 71468792741910ULL, 4639041872031973384ULL,
        9241949403303510048ULL, 18225642452025604ULL, 11547792428960448513ULL, 883832528535420940ULL,
        1020621676871808ULL, 4755836396244076672ULL, 144256063020991104ULL, 5207321538986112ULL,
        13844079548482191616ULL, 39584566214784ULL, 153140013910541312ULL, 4911179797079624192ULL,
        288559131210551810ULL, 288559131210551810ULL, 55113020883201ULL, 2594108638458347529ULL,
        10376856663482441802ULL, 1193735393409894405ULL, 2260664794027652ULL, 18225796817887362ULL,
};

struct MagicArrays {
    std::array<u64, 64> magics;
    std::array<std::array<u64, 4096>, 64> table;
};

template<Slider Type, bool MASK>
constexpr u64 getSliderAttacks(int square, u64 blocker) {
    constexpr bool ISROOK = Type == ROOK_S;
    u64 squareL = 1ULL << square;
    u64 stop = (((~lFIleOf(square) & edgeFiles) | (~lRankOf(square) & promotionRanks)) | blocker) & ~squareL;
    u64 attacks = 0;
    int shift1 = 7;
    int shift2 = 9;

    if (ISROOK) {
        shift1 = 1;
        shift2 = 8;
    }

    u64 bit = squareL;
    while ((bit & ~stop) && ((ISROOK && !(squareL & FILEA)) || (!ISROOK && !(squareL & FILEH)))) {
        bit <<= shift1;
        attacks |= bit;
    }

    bit = squareL;
    while (bit & ~stop && (ISROOK || !(squareL & FILEA))) {
        bit <<= shift2;
        attacks |= bit;
    }

    bit = squareL;
    while (bit & ~stop && (ISROOK || !(squareL & FILEH))) {
        bit >>= shift2;
        attacks |= bit;
    }

    bit = squareL;
    while (bit & ~stop && ((!ISROOK && !(squareL & FILEA)) || (ISROOK && !(squareL & FILEH)))) {
        bit >>= shift1;
        attacks |= bit;
    }

    if (MASK) {
        u64 edgeToRemove = 0ULL;
        u64 temp = 0;
        u64 fileOfRook = (FILEA >> fileOf(square));
        u64 rankOfRook = (RANK1 << rankOf(square) * 8);

        temp = fileOfRook & edgeFiles;
        if (temp)
            edgeToRemove |= edgeFiles & ~temp;
        else
            edgeToRemove |= edgeFiles;

        temp = rankOfRook & promotionRanks;
        if (temp)
            edgeToRemove |= promotionRanks & ~temp;
        else
            edgeToRemove |= promotionRanks;

        attacks &= ~edgeToRemove;
    }

    return attacks;
}

constexpr u64 randomULL(u64 seed){
    seed ^= (seed << 21);
    seed ^= (seed >> 35);
    seed ^= (seed << 4);
    return seed;
}

constexpr std::array<u64, 64> initBishopMasks() {
    std::array<u64, 64>mask = {};
    for (int i = 0; i != 64; i++)
        mask[i] = getSliderAttacks<BISHOP_S, true>(i, 0ULL);

    return mask;
}

constexpr std::array<u64, 64> initRookMasks() {
    std::array<u64, 64>mask = {};
    for (int i = 0; i != 64; i++)
        mask[i] = getSliderAttacks<ROOK_S, true>(i, 0ULL);

    return mask;
}

constexpr std::array<u64, 64> bishopMask = initBishopMasks();
constexpr std::array<u64, 64> rookMask   = initRookMasks();


template <Slider TYPE>
MagicArrays initMagics() {
    constexpr bool ISROOK = TYPE == ROOK_S;

    std::array<int, 64> shifts = ISROOK ? rookShifts : bishopShifts;
    std::array<u64, 64> masks  = ISROOK ? rookMask   :   bishopMask;
    std::array<u64, 64> magics = ISROOK ? rookMagics : bishopMagics;
    MagicArrays returnThis = {};

    //u64 random1 = randomULL(7332199340371ULL);
    //u64 random2 = randomULL(949881549754ULL);
    //u64 random3 = randomULL(3394855142990ULL);

    for (int square = 0; square != 64; square++) {
        bool done = false;
        u64 mask = masks[square];

        while (!done) {
            int loopCount = 0;
            //u64 possibleMagic = random3 & random2 & random1;
            u64 possibleMagic = magics[square];
            u64 blockers = 0;
            done = true;
            returnThis.table[square] = {0ULL};
            returnThis.magics[square] = possibleMagic;

            do {
                u64 idx = ((mask & blockers) * possibleMagic) >> shifts[square];
                u64 attacks = getSliderAttacks<TYPE, false>(square, blockers);
                loopCount++;

                if (returnThis.table[square][idx] == attacks || returnThis.table[square][idx] == 0ULL) {
                    returnThis.table[square][idx] = attacks;
                    blockers = (blockers - mask) & mask;
                } else {
                    //random1 = randomULL(random1);
                    //random2 = randomULL(random2);
                    //random3 = randomULL(random3);
                    done = false;
                    break;
                }
            } while (blockers);
        }
        //std::cout << returnThis.magics[square] << "ULL, ";
        //if (square % 4 == 3)
        //    std::cout << "\n";
    }

    return returnThis;
}

inline std::array<std::array<u64, 512>, 64> initBishopLookUpTable() {
    MagicArrays bishop = initMagics<BISHOP_S>();
    std::array<std::array<u64, 512>, 64> bishopTable{};

    for (int i = 0; i != 64; i++)
        for (int j = 0; j != 512; j++)
            bishopTable[i][j] = bishop.table[i][j];

    return bishopTable;
}

inline std::array<std::array<u64, 4096>, 64> initRookUpTable() {
    MagicArrays rook = initMagics<ROOK_S>();
    return rook.table;
}

#endif //MOLYBDENUM_MAGICBITBOARDS_H

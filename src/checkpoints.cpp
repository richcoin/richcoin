

// Copyright (c) 2013 Richcoin Developers



#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    // no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (  8, uint256("0xdc7b4eca86292d5fc5d603cc1c37babd62976ff0a3a6e340cf8dfa7f9d5fdc54"))
            ( 88, uint256("0xa4479cdd9df3aa36757da366b3c0d62989cb707d506d147b15fe791528e11115"))
            (188, uint256("0x813f7d71dab6534a39770e3955fec22ca870df502f07c450de86c92b81431e00"))
            (288, uint256("0xc09eec5bc6af16b040c5d08c2c918833371b3f61037b065a73de989d9c794f37"))
            ;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
        //return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
        //return 0;

    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
                //return NULL;
        }
        return NULL;
    }
}

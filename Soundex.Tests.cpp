#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesMultipleCharacter) {
    EXPECT_EQ(generateSoundex("ROBERT"), "R163");
    EXPECT_EQ(generateSoundex("Tymczak"), "T520");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("RUBIN"), "R150");
}



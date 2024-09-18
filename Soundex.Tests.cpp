#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, EmptyStringReturnsEmpty) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, SingleCharacterAppendsZero) {
     for (char c = 'A'; c <= 'Z'; ++c) {
        std::string expected = std::string(1, c) + "000";
        EXPECT_EQ(generateSoundex(std::string(1, c)), expected);
    }
}

TEST(SoundexTest, MultipleUpperCaseCharacters) {
    EXPECT_EQ(generateSoundex("ROBERT"), "R163");
    EXPECT_EQ(generateSoundex("TYMCZAK"), "T522");
    EXPECT_EQ(generateSoundex("PFISTER"), "P236");
    EXPECT_EQ(generateSoundex("ASHCRAFT"), "A261");
    EXPECT_EQ(generateSoundex("RUBIN"), "R150");
}

TEST(SoundexTest, MultipleLowerCaseCharacters) {
    EXPECT_EQ(generateSoundex("robert"), "R163");
    EXPECT_EQ(generateSoundex("tymczak"), "T522");
    EXPECT_EQ(generateSoundex("pfister"), "P236");
    EXPECT_EQ(generateSoundex("ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("rubin"), "R150");
    EXPECT_EQ(generateSoundex("abcdefghijklmnopqrstuvwxyz"), "A123");
}

TEST(SoundexTest, MultipleLowerAndUpperCaseCharacters) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
    EXPECT_EQ(generateSoundex("RuPeRt"), "R163");
    EXPECT_EQ(generateSoundex("AShcraft"), "A261");
    EXPECT_EQ(generateSoundex("Aeiouhw"), "A000");
    EXPECT_EQ(generateSoundex("RoBErt"), "R163");
}


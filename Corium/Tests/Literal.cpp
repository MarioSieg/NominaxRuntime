#include "TestBase.hpp"

TEST(Literal, ConvertFloatValid)
{
	ASSERT_TRUE(ConvertFloatLiteral("0").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("1").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("0.0").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("1.0").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("3.0").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("-5").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("3.15123").has_value());
	ASSERT_TRUE(ConvertFloatLiteral("-5.15123").has_value());
	
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("0").value(), 0.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("1").value(), 1.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("0.0").value(), 0.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("1.0").value(), 1.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("3.0").value(), 3.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("-5").value(), -5.0);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("3.15123").value(), 3.15123);
	ASSERT_DOUBLE_EQ(ConvertFloatLiteral("-5.15123").value(), -5.15123);
}

TEST(Literal, ConvertFloatInvalid)
{
	ASSERT_FALSE(ConvertFloatLiteral("hallo").has_value());
	ASSERT_FALSE(ConvertFloatLiteral("0.noel").has_value());
	ASSERT_FALSE(ConvertFloatLiteral("D.VA").has_value());
	ASSERT_FALSE(ConvertFloatLiteral("---2.0").has_value());
	ASSERT_FALSE(ConvertFloatLiteral("+3.21**").has_value());
}

TEST(Literal, ConvertIntValid)
{
	ASSERT_TRUE(ConvertIntLiteral("0").has_value());
	ASSERT_TRUE(ConvertIntLiteral("1").has_value());
	ASSERT_TRUE(ConvertIntLiteral("5").has_value());
	ASSERT_TRUE(ConvertIntLiteral("10").has_value());
	ASSERT_TRUE(ConvertIntLiteral("5").has_value());
	ASSERT_TRUE(ConvertIntLiteral("-10").has_value());
	
	ASSERT_EQ(ConvertIntLiteral("0").value(), 0);
	ASSERT_EQ(ConvertIntLiteral("1").value(), 1);
	ASSERT_EQ(ConvertIntLiteral("5").value(), 5);
	ASSERT_EQ(ConvertIntLiteral("10").value(), 10);
	ASSERT_EQ(ConvertIntLiteral("5").value(), 5);
	ASSERT_EQ(ConvertIntLiteral("-10").value(), -10);
}

TEST(Literal, ConvertIntValidHex)
{
	ASSERT_TRUE(ConvertIntLiteral("ABCDE", Radix::Hex).has_value());
	ASSERT_TRUE(ConvertIntLiteral("-FF00", Radix::Hex).has_value());
	ASSERT_TRUE(ConvertIntLiteral("123", Radix::Hex).has_value());
	ASSERT_TRUE(ConvertIntLiteral("7FFFFFFFFFFFFFFF", Radix::Hex).has_value());
	ASSERT_TRUE(ConvertIntLiteral("-8000000000000000", Radix::Hex).has_value());
	
	ASSERT_EQ(ConvertIntLiteral("ABCDE", Radix::Hex), 0xABCDE);
	ASSERT_EQ(ConvertIntLiteral("-FF00", Radix::Hex), -0xFF00);
	ASSERT_EQ(ConvertIntLiteral("123", Radix::Hex), 0x123);
	ASSERT_EQ(ConvertIntLiteral("7FFFFFFFFFFFFFFF", Radix::Hex), std::numeric_limits<I64>::max());
	ASSERT_EQ(ConvertIntLiteral("-8000000000000000", Radix::Hex), std::numeric_limits<I64>::min());
}

TEST(Literal, ConvertIntValidBin)
{
	ASSERT_TRUE(ConvertIntLiteral("101001", Radix::Bin).has_value());
	ASSERT_TRUE(ConvertIntLiteral("-110101", Radix::Bin).has_value());
	ASSERT_TRUE(ConvertIntLiteral("11011", Radix::Bin).has_value());
	ASSERT_TRUE(ConvertIntLiteral("11111111111111111111111111111111", Radix::Bin).has_value());

	ASSERT_EQ(ConvertIntLiteral("101001", Radix::Bin), 0b101001);
	ASSERT_EQ(ConvertIntLiteral("-110101", Radix::Bin), -0b110101);
	ASSERT_EQ(ConvertIntLiteral("11011", Radix::Bin), 0b11011);
	ASSERT_EQ(ConvertIntLiteral("11111111111111111111111111111111", Radix::Bin), 0b11111111111111111111111111111111);
}

TEST(Literal, ConvertIntInvalid)
{
	ASSERT_FALSE(ConvertIntLiteral("").has_value());
	ASSERT_FALSE(ConvertIntLiteral("hallo").has_value());
	ASSERT_FALSE(ConvertIntLiteral("D.VA").has_value());
	ASSERT_FALSE(ConvertIntLiteral("3.2").has_value());
	ASSERT_FALSE(ConvertIntLiteral("0c8").has_value());
	ASSERT_FALSE(ConvertIntLiteral("7233", Radix::Bin).has_value());
	ASSERT_FALSE(ConvertIntLiteral("3.2332", Radix::Hex).has_value());
}

TEST(Literal, DetermineTypeFloat)
{
	ASSERT_EQ(DetermineLiteralType("3.1"), EstimatedLiteralType::Float);
	ASSERT_EQ(DetermineLiteralType("0.0"), EstimatedLiteralType::Float);
	ASSERT_EQ(DetermineLiteralType("2.1"), EstimatedLiteralType::Float);
	ASSERT_EQ(DetermineLiteralType("0.9"), EstimatedLiteralType::Float);
}

TEST(Literal, DetermineTypeInt)
{
	ASSERT_EQ(DetermineLiteralType("3"), EstimatedLiteralType::Int);
	ASSERT_EQ(DetermineLiteralType("0b1111201"), EstimatedLiteralType::Int);
	ASSERT_EQ(DetermineLiteralType("0xFFAABB"), EstimatedLiteralType::Int);
	ASSERT_EQ(DetermineLiteralType("-1037272"), EstimatedLiteralType::Int);
}

/**
 * \file Item.h
 *
 * \author Hector
 *
 * Base class for items
 *
 * Controls how the items work
 */

#pragma once
#include <memory>
#include <string>

class CGame;

class CItem
{
protected:
	/**
	* Override function
	* \param game, filename
	*/
	CItem::CItem(CGame *game, const std::wstring &filename);

public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	virtual ~CItem();

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	///Draw Image
	void CItem::Draw(Gdiplus::Graphics *graphics);

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

private:
	/// The game this item is contained in
	CGame  *mGameTiles;

	/// The image of this item
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;


	/// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
};


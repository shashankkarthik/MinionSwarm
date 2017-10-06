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
	* \param aquarium, filename
	*/
	CItem::CItem(CGame *game, const std::wstring &filename);

public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	virtual ~CItem();
private:
	/// The aquarium this item is contained in
	CGame  *mGameTiles;

	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;


	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
};


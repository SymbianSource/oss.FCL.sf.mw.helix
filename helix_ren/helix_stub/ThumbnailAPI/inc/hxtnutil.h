/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: hxtnutil.h,v 1.1 2008/01/24 17:10:32 gashish Exp $
 *
 * Portions Copyright (c) 1995-2004 RealNetworks, Inc. All Rights Reserved.
 *
 * The contents of this file, and the files included with this file,
 * are subject to the current version of the RealNetworks Public
 * Source License (the "RPSL") available at
 * http://www.helixcommunity.org/content/rpsl unless you have licensed
 * the file under the current version of the RealNetworks Community
 * Source License (the "RCSL") available at
 * http://www.helixcommunity.org/content/rcsl, in which case the RCSL
 * will apply. You may also obtain the license terms directly from
 * RealNetworks.  You may not use this file except in compliance with
 * the RPSL or, if you have a valid RCSL with RealNetworks applicable
 * to this file, the RCSL.  Please see the applicable RPSL or RCSL for
 * the rights, obligations and limitations governing use of the
 * contents of the file.
 *
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 or later (the
 * "GPL") in which case the provisions of the GPL are applicable
 * instead of those above. If you wish to allow use of your version of
 * this file only under the terms of the GPL, and not to allow others
 * to use your version of this file under the terms of either the RPSL
 * or RCSL, indicate your decision by deleting the provisions above
 * and replace them with the notice and other provisions required by
 * the GPL. If you do not delete the provisions above, a recipient may
 * use your version of this file under the terms of any one of the
 * RPSL, the RCSL or the GPL.
 *
 * This file is part of the Helix DNA Technology. RealNetworks is the
 * developer of the Original Code and owns the copyrights in the
 * portions it created.
 *
 * This file, and the files included with this file, is distributed
 * and made available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS
 * ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
 *
 * Technology Compatibility Kit Test Suite(s) Location:
 *    http://www.helixcommunity.org/content/tck
 *
 * Contributor(s):
 * Portions Copyright (c) 2002-2010 Nokia Corporation and/or its subsidiary(-ies).
 * ***** END LICENSE BLOCK ***** */

#ifndef _SYMBIAN_TE_UTIL_H_
#define _SYMBIAN_TE_UTIL_H_

// Symbian includes
#include <f32file.h> // RFile 

#include "hxmetadatakeys.h"
#include "hxtnutil_obs.h"




// CHXThumbnailUtility is the entry point for TE engine.
// It enables access to Helix Thumbnail engine for reading
// the decoded YUV frames for a given file.

class CHXThumbnailUtility : public CBase         
{
public:
    ~CHXThumbnailUtility();
    
     /**
     * Constructs a new CHXThumbnailUtility object. This method
     * may leave if no resources are available to construct 
     * a new object.    
     * 
     * Possible leave codes:
     *  - <code>KErrNoMemory</code> if memory allocation fails
     *     
     * @param aObserver  observer to notify when info is ready for reading
     *
     * @return  pointer to a new CHXThumbnailUtility instance
     */

    static CHXThumbnailUtility* NewL(MHXThumbnailUtilityImplObserver& aObserver);
                                                                  
    /**
     * OpenFileL reads data from aFileHandle to get information
     * about the specified video clip file.
     * Possible leave codes:
     *  - <code>KErrNoMemory</code> if memory allocation fails
     *  - <code>KErrNotSupported</code> if can't support this clip for thumbnail.   
     *  - <code>KErrNotFound</code> if can't find a good thumbnail.   
     *
     * @param aFileHandle  File handle of file to get the thumbnail.
     * @param uStartPositingMS  Starting position in clip time from which to 
                                read the thumbnail.     
     */

    void    OpenFileL(const RFile& aFileHandle, TUint uStartPositingMS = 0);

    
    /**
     * Cancels frame generation. If no frame is currently being 
     * generated, the function does nothing. Can be called multiple times
     * without any side effects.
     */
    
    void CancelThumb();
    

    /** returns the count of metadata entries.
      * @param aCount  Number of metadata entries returned.
      * @return  System wide error code if there is any error.
     */
    
    TInt GetMetaDataCount(TUint &aCount);

    /** returns the metadata entry at the given index
      * @param aIndex  aIndex of the metadata entry.
      * @param id returned id or key of the metadata entry.
      * @param pDes returned value of the metadata entry. It is not 
                    owned by the caller.
      * @return  System wide error code if there is any error.             
     */
        
    TInt GetMetaDataAt(TUint aIndex, 
            HXMetaDataKeys::EHXMetaDataId &id, HBufC*& pDes);

protected:
    CHXThumbnailUtility();

private:
    void    ConstructL(MHXThumbnailUtilityImplObserver& aObserver);    
    
         
};


#endif _SYMBIAN_TE_UTIL_H_


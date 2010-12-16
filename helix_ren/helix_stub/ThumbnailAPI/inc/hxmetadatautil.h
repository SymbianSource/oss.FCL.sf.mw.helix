/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id $
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
 * terms of the GNU General Public License Version 2 (the
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
 *
 * ***** END LICENSE BLOCK ***** */



#ifndef _SYMBIAN_METADATA_UTIL_IMP_H_
#define _SYMBIAN_METADATA_UTIL_IMP_H_

// Symbian includes
#include <f32file.h> // RFile 

#include "hxmetadatakeys.h"




// CHXMetaDataUtility is the entry point for metadata engine.
// This hides all the implmentation details of the actual metadata engine
// including Helix specfic details like GlobalManager, Location of the dlls etc.

class CHXMetaDataUtility : public CBase
{
public:
         ~CHXMetaDataUtility();
        static CHXMetaDataUtility* NewL();

        // Opens the file aFileName for metadata reading.
        // descriptor aFileName can be deleted after the OpenFileL returns.
         void OpenFileL( const TDesC& aFileName );

        // Opens the descriptor for metadata reading.
        // descriptor is required to be present till ResetL is being called.
         void OpenDesL(const TDesC8& aDes);

        // Opens the descriptor for metadata reading.
        // File Handle can be closed after the OpenFileL returns.
         void OpenFileL(RFile& aFile);

        // Resets the utility. Must be called before OpenFileL() or 
        // OpenDesL() can be called again.
        // 
         void ResetL();

        // returns the count of metadata entries.
         TInt GetMetaDataCount(TUint &aCount);

        // returns the Metadata entry at index a Index. 
        // pDes is not owned by the caller.
         TInt GetMetaDataAt(TUint aIndex, 
                    HXMetaDataKeys::EHXMetaDataId &id, HBufC*& pDes);

private:
        CHXMetaDataUtility();
        CHXMetaDataUtility* ConstructL();

        // utility functions
        void* GetSymbol(RLibrary &rlib, const char *symbolName);
        void  ConvertMetaDataL();

private:
        typedef int (*GetSym2Ord)(const char* pSymbolName);   
        RLibrary                    m_rlib;
        
        TBool                       m_bLibLoaded;
        TBool                       m_bCloseNeeded;

};

#endif _SYMBIAN_METADATA_UTIL_IMP_H_


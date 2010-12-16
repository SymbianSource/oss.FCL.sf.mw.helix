/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: hxmetadatakeys.h,v 1.3.66.2 2010/09/01 17:03:50 yuryrp Exp $
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

#ifndef _SYMBIAN_METADATA_KEYS_H_
#define _SYMBIAN_METADATA_KEYS_H_

struct HXMetaDataKeys
{
public:
    enum EHXMetaDataKeyType {
        EInteger=0,
        EBoolean,
        EBuffer,        
        EString
    };

    enum EHXMetaDataId {
        EHXTitle      = 0,
        EHXCopyright, 
        EHXAuthor,   
        EHXGenre,  
        EHXPerformer,
        EHXDescription,
        EHXLiveStream,
        EHXSeekable, 
        EHXContentType,  
        EHXFormat,       
        EHXQuality,      
        EHXAbstract,     
        EHXDuration,         
        EHXClipBitRate,      
        EHXFramesPerSecond, 
        EHXFrameSize,      
        EHXStreamCount,   
        EHXVideoBitRate,
        EHXAudioBitRate,  
        EHXMimeType,  
        EHXCodec,
        EHXIconURI,
        EHXEPreviewURI,
        EHXContentURI,
        EHXContentID,
        EHXInfoURL 
    };

    EHXMetaDataId        m_id;
    const char*          m_pHXKey;
    EHXMetaDataKeyType   m_eType;
};


#define HXTitle        "Title"      
#define HXCopyright    "Copyright" 
#define HXAuthor       "Author"   
#define HXAbstract     "Abstract" 
#define HXGenre        "Genre"  
#define HXPerformer    "Performer"  
#define HXContentType  "ContentType"
#define HXLiveStream   "LiveStream"
#define HXSeekable     "Seekable" 

static const HXMetaDataKeys HXMetaDataKeyTab[] = {
    {  HXMetaDataKeys::EHXTitle        , HXTitle         ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXCopyright    , HXCopyright     ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXAuthor       , HXAuthor        ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXAbstract     , HXAbstract      ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXGenre        , HXGenre         ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXPerformer    , HXPerformer     ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXContentType  , HXContentType   ,HXMetaDataKeys::EBuffer  }
    ,{ HXMetaDataKeys::EHXLiveStream   , HXLiveStream    ,HXMetaDataKeys::EInteger }
    ,{ HXMetaDataKeys::EHXSeekable     , HXSeekable      ,HXMetaDataKeys::EInteger }
};

static const HXMetaDataKeys HXStreamMetaDataKeyTab[] = {
    { HXMetaDataKeys::EHXMimeType      , "MimeType"      ,HXMetaDataKeys::EString  }
    ,{ HXMetaDataKeys::EHXCodec        , "Codec"         ,HXMetaDataKeys::EString  }
};


#endif _SYMBIAN_METADATA_KEYS_H_


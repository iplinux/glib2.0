/* GIO - GLib Input, Output and Streaming Library
 * 
 * Copyright (C) 2006-2007 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Alexander Larsson <alexl@redhat.com>
 */

#ifndef __G_FILE_ICON_H__
#define __G_FILE_ICON_H__

#include <gio/gloadableicon.h>
#include <gio/gfile.h>

G_BEGIN_DECLS

#define G_TYPE_FILE_ICON         (g_file_icon_get_type ())
#define G_FILE_ICON(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_FILE_ICON, GFileIcon))
#define G_FILE_ICON_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_FILE_ICON, GFileIconClass))
#define G_IS_FILE_ICON(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_FILE_ICON))
#define G_IS_FILE_ICON_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_FILE_ICON))
#define G_FILE_ICON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), G_TYPE_FILE_ICON, GFileIconClass))

typedef struct _GFileIcon        GFileIcon;
typedef struct _GFileIconClass   GFileIconClass;

GType g_file_icon_get_type (void) G_GNUC_CONST;
  
GIcon *g_file_icon_new (GFile *file);

GFile *g_file_icon_get_file (GFileIcon *icon);

G_END_DECLS

#endif /* __G_FILE_ICON_H__ */
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ur3_llm_control__srv__ExecuteSkill_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteSkill_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub skill: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone: std::string::String,

}



impl Default for ExecuteSkill_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ExecuteSkill_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteSkill_Request {
  type RmwMsg = super::srv::rmw::ExecuteSkill_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        skill: msg.skill.as_str().into(),
        object: msg.object.as_str().into(),
        zone: msg.zone.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        skill: msg.skill.as_str().into(),
        object: msg.object.as_str().into(),
        zone: msg.zone.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      skill: msg.skill.to_string(),
      object: msg.object.to_string(),
      zone: msg.zone.to_string(),
    }
  }
}


// Corresponds to ur3_llm_control__srv__ExecuteSkill_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteSkill_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub status: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for ExecuteSkill_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ExecuteSkill_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteSkill_Response {
  type RmwMsg = super::srv::rmw::ExecuteSkill_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        status: msg.status.as_str().into(),
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        status: msg.status.as_str().into(),
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      status: msg.status.to_string(),
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to ur3_llm_control__srv__SetAttachment_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetAttachment_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub action: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object: std::string::String,

}



impl Default for SetAttachment_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetAttachment_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetAttachment_Request {
  type RmwMsg = super::srv::rmw::SetAttachment_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action: msg.action.as_str().into(),
        object: msg.object.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        action: msg.action.as_str().into(),
        object: msg.object.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      action: msg.action.to_string(),
      object: msg.object.to_string(),
    }
  }
}


// Corresponds to ur3_llm_control__srv__SetAttachment_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetAttachment_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SetAttachment_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetAttachment_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetAttachment_Response {
  type RmwMsg = super::srv::rmw::SetAttachment_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to ur3_llm_control__srv__GetWorldState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWorldState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub structure_needs_at_least_one_member: u8,

}



impl Default for GetWorldState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetWorldState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetWorldState_Request {
  type RmwMsg = super::srv::rmw::GetWorldState_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      structure_needs_at_least_one_member: msg.structure_needs_at_least_one_member,
    }
  }
}


// Corresponds to ur3_llm_control__srv__GetWorldState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetWorldState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub objects: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub locations: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub held_object: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub camera_ready: bool,

}



impl Default for GetWorldState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetWorldState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetWorldState_Response {
  type RmwMsg = super::srv::rmw::GetWorldState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        objects: msg.objects
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        locations: msg.locations
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        held_object: msg.held_object.as_str().into(),
        x: msg.x.as_slice().into(),
        y: msg.y.as_slice().into(),
        camera_ready: msg.camera_ready,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        objects: msg.objects
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        locations: msg.locations
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        held_object: msg.held_object.as_str().into(),
        x: msg.x.as_slice().into(),
        y: msg.y.as_slice().into(),
      camera_ready: msg.camera_ready,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      objects: msg.objects
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      locations: msg.locations
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      held_object: msg.held_object.to_string(),
      x: msg.x.into(),
      y: msg.y.into(),
      camera_ready: msg.camera_ready,
    }
  }
}






#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__ExecuteSkill() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__ExecuteSkill
#[allow(missing_docs, non_camel_case_types)]
pub struct ExecuteSkill;

impl rosidl_runtime_rs::Service for ExecuteSkill {
    type Request = ExecuteSkill_Request;
    type Response = ExecuteSkill_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__ExecuteSkill() }
    }
}




#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__SetAttachment() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__SetAttachment
#[allow(missing_docs, non_camel_case_types)]
pub struct SetAttachment;

impl rosidl_runtime_rs::Service for SetAttachment {
    type Request = SetAttachment_Request;
    type Response = SetAttachment_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__SetAttachment() }
    }
}




#[link(name = "ur3_llm_control__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__GetWorldState() -> *const std::ffi::c_void;
}

// Corresponds to ur3_llm_control__srv__GetWorldState
#[allow(missing_docs, non_camel_case_types)]
pub struct GetWorldState;

impl rosidl_runtime_rs::Service for GetWorldState {
    type Request = GetWorldState_Request;
    type Response = GetWorldState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ur3_llm_control__srv__GetWorldState() }
    }
}


